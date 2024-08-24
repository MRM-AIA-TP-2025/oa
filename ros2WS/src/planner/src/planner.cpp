#include <rclcpp/rclcpp.hpp>
#include "include/planner.hpp"  // Ensure this path is correct

int main(int argc, char * argv[])
{
    // Initialize the ROS 2 client library
    rclcpp::init(argc, argv);

    // Define your topic names
    std::string imu_topic = "/imu_data";
    std::string gps_topic = "/gps";
    std::string aruco_topic = "/aruco_detect";
    std::string lidar_topic = "/scan";

    // Create the node with your sensor callbacks
    auto node = std::make_shared<planner::SensorCallback>(imu_topic, aruco_topic,gps_topic , lidar_topic);

    // Create a MultiThreadedExecutor with 4 threads
    rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 0);
    
    // Add the node to the executor
    executor.add_node(node);

    // Spin the executor to handle callbacks
    executor.spin();

    // Shutdown ROS 2
    rclcpp::shutdown();
    
    return 0;
}
