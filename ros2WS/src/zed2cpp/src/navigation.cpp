#include <rclcpp/rclcpp.hpp>
#include <sensors/msg/pclo.hpp>
#include <sensors/msg/navigation_data.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <cmath>

struct obstacleLocationStruct
{
    bool left;
    bool right;
    bool center;
};

class ObstacleAvoidancePCL : public rclcpp::Node
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
    rclcpp::Subscription<sensors::msg::NavigationData>::SharedPtr nav_data_subscriber_;
    rclcpp::Subscription<sensors::msg::Pclo>::SharedPtr pcl_data_subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;  // Timer to replace the infinite loop

    geometry_msgs::msg::Twist output_;
    rclcpp::Duration interval_;
    sensors::msg::NavigationData nav_data_;
    sensors::msg::Pclo pcl_data_;
    bool obstacle_in_path_;
    enum State { GOAL_REACHED, CALIBRATING, MOVING };
    std::string current_state_string_;
    State current_state_;
    double angular_difference_;
    bool first_encounter_;
    bool front_ = false;
    bool left_ = false;
    bool right_ = false;

    double hitpoint_distance_, leave_point_distance_;

    bool isClockWiseCloser()
    {
        double clockwise_distance = fmod(nav_data_.bearing - nav_data_.orientation + 360.0, 360.0);
        double counterclockwise_distance = fmod(nav_data_.orientation - nav_data_.bearing + 360.0, 360.0);
        if (clockwise_distance > 175 && counterclockwise_distance > 175 && abs(clockwise_distance - counterclockwise_distance) < 1){
            return true;
        }
        if (clockwise_distance < counterclockwise_distance){
            return true;
        }
        return false;
    }

    void getCurrentState()
    {
        switch (current_state_)
        {
        case GOAL_REACHED:
            current_state_string_ = "GoalReached";
            break;
        case CALIBRATING:
            current_state_string_ = "Calibrating";
            break;
        case MOVING:
            current_state_string_ = "Moving To Goal";
            break;
        default:
            current_state_string_ = "Error";
        }
    }

    void normalNav()
    {
        first_encounter_ = true;
        current_state_ = CALIBRATING;
        rclcpp::Rate loop_rate(50);
        getCurrentState();

        if (nav_data_.distance < 0.2)
        {
            current_state_ = GOAL_REACHED;
            output_.linear.x = output_.angular.z = 0;
            cmd_vel_publisher_->publish(output_);
            return;
        }

        if (front_ == 1)
        {
            hitpoint_distance_ = nav_data_.distance;
            obstacle_in_path_ = true;
            return;
        }

        else if (current_state_ == GOAL_REACHED)
            current_state_ = CALIBRATING;

        if (current_state_ != GOAL_REACHED)
        {
            angular_difference_ = nav_data_.bearing - nav_data_.orientation -180  ;
            if (angular_difference_ < 5 && angular_difference_ > -5 || angular_difference_>355 && angular_difference_<365 || angular_difference_<-355 && angular_difference_>-365 )
                current_state_ = MOVING;
            else
                current_state_ = CALIBRATING;
        }

        switch (current_state_)
        {
        case GOAL_REACHED:
            output_.linear.x = output_.angular.z = 0;
            break;
        case CALIBRATING:
            output_.linear.x = 0;
            if (isClockWiseCloser())
                
                output_.angular.z = -0.8;
            else
                output_.angular.z = 0.8;
            break;
        case MOVING:
            output_.angular.z = 0;
            if (angular_difference_ > 0.5 || angular_difference_ < -0.5)
            {   
                if (isClockWiseCloser())
                    output_.angular.z = -0.8;
                else
                    output_.angular.z = 0.8;
            }
            output_.linear.x = 0.5;
            break;
        default:
            break;
        }
        cmd_vel_publisher_->publish(output_);
    }

    void pclCallback(const sensors::msg::Pclo::SharedPtr msg)
    {
        pcl_data_ = *msg;
        front_ = pcl_data_.front;
        left_ = pcl_data_.left;
        right_ = pcl_data_.right;
    }

    void navDataCallback(const sensors::msg::NavigationData::SharedPtr msg)
    {
        nav_data_ = *msg;
    }

    void update()
    {
        if (nav_data_.isonline)
        {
            leave_point_distance_ = nav_data_.distance;
            if (leave_point_distance_ < hitpoint_distance_ && fabs(leave_point_distance_ - hitpoint_distance_) > 0.5)
            {
                obstacle_in_path_ = false;
                hitpoint_distance_ = nav_data_.distance;
            }
        }
    }

    void timerCallback()
    {
        if (obstacle_in_path_)
        {
            RCLCPP_INFO(this->get_logger(),"oa");
            update();
            if (first_encounter_)
            {
                RCLCPP_INFO(this->get_logger(), "First Encounter");
                output_.angular.z = -2;
                output_.linear.x = 0;
                cmd_vel_publisher_->publish(output_);
                first_encounter_ = false;
                rclcpp::sleep_for(std::chrono::seconds(1));
            }

            if (nav_data_.distance > 0.2)
            {
                if (left_ == 0 && right_ == 0 && front_ == 0)
                {
                    output_.angular.z = 0.8;
                    output_.linear.x = 0.5;
                }
                else if (left_ == 1 && front_ == 0)
                {
                    output_.angular.z = 0;
                    output_.linear.x = 0.5;
                }
                else
                {
                    output_.angular.z = -1;
                    output_.linear.x = 0;
                }
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "Goal Reached");
                output_.angular.z = 0;
                output_.linear.x = 0;
            }
            cmd_vel_publisher_->publish(output_);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(),"nav");
            normalNav();
        }
    }

public:
    ObstacleAvoidancePCL() : Node("obstacle_avoidance"), interval_(rclcpp::Duration::from_seconds(2.5))
    {
        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        pcl_data_subscriber_ = this->create_subscription<sensors::msg::Pclo>("/pcl_data", 10, std::bind(&ObstacleAvoidancePCL::pclCallback, this, std::placeholders::_1));
        nav_data_subscriber_ = this->create_subscription<sensors::msg::NavigationData>("/navigation_data", 10, std::bind(&ObstacleAvoidancePCL::navDataCallback, this, std::placeholders::_1));

        obstacle_in_path_ = true;
        nav_data_.distance = 0;
        hitpoint_distance_ = 9999999999;
        output_.linear.x = output_.linear.y = output_.linear.z = output_.angular.x = output_.angular.y = output_.angular.z = 0;

        // Create a timer that calls the timerCallback function at the rate of 20Hz
        timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&ObstacleAvoidancePCL::timerCallback, this));
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ObstacleAvoidancePCL>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
