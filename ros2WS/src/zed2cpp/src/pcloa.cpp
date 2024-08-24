#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl/common/common.h>
#include <pcl/features/normal_3d.h>
#include <sensors/msg/pclo.hpp>

using namespace std::chrono_literals;

class PCLPreprocessingNode : public rclcpp::Node
{
public:
  PCLPreprocessingNode()
  : Node("pcl_preprocessing_node")
  {
    subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
      "/zed2_left_camera/points", 1,
      std::bind(&PCLPreprocessingNode::point_cloud_callback, this, std::placeholders::_1));
    publisher_ = this->create_publisher<sensors::msg::Pclo>(
      "/pcl_data", 10);
    filtered_pcl_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("/obstacles", 10);
    RCLCPP_INFO(this->get_logger(), "PCL Preprocessing Node has been started");
  }

private:
  bool front = false;
  bool left = false;
  bool right = false;
  double front_threshold = 1.4;
  double front_side_threshold = 1.0;
  double side_threshold = 0.6;
  double side_threshold_front = 0.5;
  const double leaf_size = 0.1;
  sensors::msg::Pclo output_;
  void point_cloud_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
  {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*msg, *cloud);

    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(0.0, 5.0); 
    pcl::PointCloud<pcl::PointXYZ>::Ptr pass_filtered_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pass.filter(*pass_filtered_cloud);

    pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::VoxelGrid<pcl::PointXYZ> voxel_filter;
    voxel_filter.setInputCloud(pass_filtered_cloud);
    voxel_filter.setLeafSize(0.1,0.1,0.1);
    voxel_filter.filter(*filtered_cloud);

    pcl::SACSegmentation<pcl::PointXYZ> seg;
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);

    seg.setOptimizeCoefficients(true);
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setDistanceThreshold(0.01);
    seg.setMaxIterations(1000);

    // Segment the largest planar component from the cloud
    seg.setInputCloud(filtered_cloud);
    seg.segment(*inliers, *coefficients);

    if (inliers->indices.empty()) {
        RCLCPP_WARN(this->get_logger(), "Could not estimate a planar model for the given dataset.");
        return;
    }

    // Extract the points not part of the ground plane
    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud(filtered_cloud);
    extract.setIndices(inliers);
    extract.setNegative(true);  // true removes the ground plane
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
    extract.filter(*cloud_filtered);

    sensor_msgs::msg::PointCloud2 output;
    pcl::toROSMsg(*cloud_filtered, output);
    output.header = msg->header;
    filtered_pcl_publisher_->publish(output);

    front = false;
    left = false;
    right = false;
    for (const auto& point : cloud_filtered->points) {
        if (point.z < front_side_threshold) {
            if (point.x < -side_threshold)
                left = true;
            else if (point.x > side_threshold)
                right = true;
        }
        if (point.z < front_threshold && abs(point.x) < side_threshold_front)
            front = true;
    }
    output_.front = front;
    output_.left = left;
    output_.right = right;
    publisher_->publish(output_);
    // Convert to ROS message and publish

    RCLCPP_INFO(this->get_logger(), "Published processed point cloud");
  }

  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_;
  rclcpp::Publisher<sensors::msg::Pclo>::SharedPtr publisher_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr filtered_pcl_publisher_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PCLPreprocessingNode>());
  rclcpp::shutdown();
  return 0;
}