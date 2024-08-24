#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensors/msg/navigation_data.hpp>
#include <cmath>
#include <chrono>  // Include this header for std::chrono

using namespace std::chrono_literals;  // Use this namespace for chrono literals

struct Line {
    double slope;
    double intercept;
};

class Navigation : public rclcpp::Node, public std::enable_shared_from_this<Navigation>
{
private:
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr gps_subscriber_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscriber_;
    rclcpp::Publisher<sensors::msg::NavigationData>::SharedPtr goal_publisher_;
    sensor_msgs::msg::NavSatFix gps_data_;
    sensor_msgs::msg::Imu imu_data_;
    double latitude_, longitude_;
    bool has_reached_, got_goal_;
    Line line_; 
    rclcpp::TimerBase::SharedPtr timer_;

    const double R = 6371000.0;  // Radius of Earth in meters
    sensors::msg::NavigationData nav_data_;

    void gps_callback(const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
        gps_data_ = *msg;
    }

    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg) {
        imu_data_ = *msg;
    }

    void calculate_data() {
        double bearing, distance;
        double latt1 = gps_data_.latitude * M_PI / 180.0;
        double long1 = gps_data_.longitude * M_PI / 180.0;
        double latt2 = latitude_ * M_PI / 180.0;
        double long2 = longitude_ * M_PI / 180.0;

        double dlat = latt2 - latt1;
        double dlon = long2 - long1;
        
        // Haversine formula
        double a = sin(dlat / 2.0) * sin(dlat / 2.0) +
                   cos(latt1) * cos(latt2) *
                   sin(dlon / 2.0) * sin(dlon / 2.0);
        double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
        distance = R * c;

        // Calculate bearing
        double x = sin(dlon) * cos(latt2);
        double y = cos(latt1) * sin(latt2) - sin(latt1) * cos(latt2) * cos(dlon);
        bearing = atan2(y, x);
        bearing = fmod((bearing + 2.0 * M_PI), (2.0 * M_PI));
        bearing *= 180.0 / M_PI;

        nav_data_.bearing = bearing;
        nav_data_.distance = distance;
    }
    
    void calculate_yaw() {
        double x = imu_data_.orientation.x;
        double y = imu_data_.orientation.y;
        double z = imu_data_.orientation.z;
        double w = imu_data_.orientation.w;
        double sinr_cosp = +2.0 * (w * z + x * y);
        double cosr_cosp = +1.0 - 2.0 * (y * y + z * z);
        double yaw = atan2(sinr_cosp, cosr_cosp);
        yaw *= 180.0 / M_PI; 
        yaw = fmod(yaw + 360.0, 360.0);
        nav_data_.orientation = yaw;
    }

    void set_line() {
        line_.slope = (latitude_ - gps_data_.latitude) / (longitude_ - gps_data_.longitude);
        line_.intercept = gps_data_.latitude - line_.slope * gps_data_.longitude;
    }

    void check_if_on_line() {
        double distance = (fabs(gps_data_.latitude - line_.slope * gps_data_.longitude - line_.intercept)) / (sqrt(1 + line_.slope * line_.slope));
        nav_data_.isonline = distance < 0.000002;
    }

    void get_goal() {
        RCLCPP_INFO(this->get_logger(), "Input goal (Latitude and Longitude):");
        std::cin >> latitude_ >> longitude_;
        has_reached_ = false;
        got_goal_ = true;
        set_line();
    }

    void timer_callback() {
        if (has_reached_) {
            get_goal();
        }

        if (got_goal_) {
            calculate_data();
            calculate_yaw();
            check_if_on_line();

            RCLCPP_INFO(this->get_logger(), "Distance: %lf Bearing: %lf Orientation: %lf isOnLine: %d",
                        nav_data_.distance, nav_data_.bearing, nav_data_.orientation, nav_data_.isonline);

            if (nav_data_.distance < 0.2) {
                has_reached_ = true;
                got_goal_ = false;
            }

            goal_publisher_->publish(nav_data_);
        }
    }

public:
    Navigation() : Node("navigation"), has_reached_(true), got_goal_(false)
    {
        gps_subscriber_ = this->create_subscription<sensor_msgs::msg::NavSatFix>(
            "/gps", 10, std::bind(&Navigation::gps_callback, this, std::placeholders::_1));
        imu_subscriber_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "/imu/imu_data", 1, std::bind(&Navigation::imu_callback, this, std::placeholders::_1));
        goal_publisher_ = this->create_publisher<sensors::msg::NavigationData>("/navigation_data", 10);

        // Correct the timer initialization
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20), std::bind(&Navigation::timer_callback, this));
    }
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto nav = std::make_shared<Navigation>();
    rclcpp::spin(nav);
    rclcpp::shutdown();
    return 0;
}
