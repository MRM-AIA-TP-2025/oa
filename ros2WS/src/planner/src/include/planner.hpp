#ifndef IRC_PLANNER_H_
#define IRC_PLANNER_H_

#include <rclcpp/rclcpp.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>

#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "sensors/msg/imu_data.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/empty.hpp"
#include "stereo/msg/tag.hpp"
#include "stereo/msg/yolotag.hpp"
#include "std_msgs/msg/int32.hpp"

using std::placeholders::_1;

namespace planner
{
    // Static Variable Definitions

    // Rover Dimensions and Physical Properties

    const double kRoverLength = 1.40;
    const double kRoverBreadth = 1.11;
    const double kLidarPos = 0.43; // y distance from the Top-Center of the Rover

    // const double kRoverLength = 0.5;
    // const double kRoverBreadth = 0.4;
    // const double kLidarPos = 0.02; 

    // Rover Speed & Obstacle constraints and parameters

    const double kMaxLinearVel = 0.5;
    const double kMinLinearVel = 0;

    const double kMaxAngularVel = 1.12;
    const double kMinAngularVel = 0;

    const double kMaxObsThreshold = 1.5;
    const double kMinObsThreshold = 0.3;
    const double kMinYObsThreshold = 0.3;

    const double kMaxXObjThreshold = 1.0;
    const double kMinXObjThreshold = 0.3;
    const double kMaxYObjThreshold = 1.0;
    const double kMinYObjThreshold = 0.3;

    // Sensor Data Thresholds

    const int kLidarAngularRange = 360;
    const int kLidarSamples = 430;

    // Goal Distance Threshold

    // const double kDistanceTHreshold = 1;
    // const int task_goal_count = 7;

    // Enum for Rover state
    // Class defines different states of the rover during the misson including:
    // 1. Search Pattern following
    // 2. Aruco Tag Following
    // 3. Coordinate Following
    // 4. Obstacle Avoidance
    // 5. Data Analysis

    enum State
    {
        kSearchPattern,
        kArucoFollowing,
        kCoordinateFollowing,
        kObstacleAvoidance,
        kDataAnalysis
    };

    enum SearchPatternType
    {
        kGoalCircle,
        kPatternFollowing,
        kTerminate
    };

    // Struct for Latitude and Longitude
    typedef struct Coordinates
    {
        double latitude;
        double longitude;
    } Coordinates;

    class SensorCallback : public rclcpp::Node
    {
    public:
        SensorCallback(std::string imu_topic, std::string aruco_topic, std::string gps_topic, std::string lidar_topic) : Node("planner_node")
        {
            // Requesting GPS Coordinate input from the user

            getCoordinates();

            // setting custom callback queue for node

            // Initializing Publishers
            vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 1);

            // Initializing Subscribers
            
            imu_sub = this->create_subscription<sensors::msg::ImuData>(imu_topic, 10, std::bind(&SensorCallback::imuCallback, this, _1));
            gps_sub = this->create_subscription<sensor_msgs::msg::NavSatFix>(gps_topic, 10, std::bind(&SensorCallback::gpsCallback, this, _1));
            lidar_sub = this->create_subscription<sensor_msgs::msg::LaserScan>(lidar_topic, 10, std::bind(&SensorCallback::lidarCallback, this, _1));
            aruco_sub = this->create_subscription<stereo::msg::Yolotag>(aruco_topic, 10, std::bind(&SensorCallback::arucoCallback, this, _1));
            state_pub = this->create_publisher<std_msgs::msg::Int32>("/state_topic", 1);

            //  Formation of Equations

            obs_avoid_linear = straightLineEquation(kMinObsThreshold, 0, kMaxObsThreshold, kMaxLinearVel);
            obs_avoid_angular = straightLineEquation(kRoverBreadth / 2, 0, 0, kMaxAngularVel);
            obj_follow_linear = straightLineEquation(2, kMaxLinearVel*0.8, 1, 0);
            obj_follow_angular = straightLineEquation(0, 0, 16, kMaxAngularVel);
            coord_follow_angular = straightLineEquation(0.3, 0.5, 3.14, kMaxAngularVel);

            lidar_center = kLidarSamples / 2;
            lidar_min_range =
                lidar_center - ((atan(kRoverBreadth / 2 / kLidarPos) * 180 / M_PI) * kLidarSamples / kLidarAngularRange);
            lidar_max_range =
                lidar_center + ((atan(kRoverBreadth / 2 / kLidarPos) * 180 / M_PI) * kLidarSamples / kLidarAngularRange);

            
        };

        void setAngOffset(float offset){
            setAngularOffset(offset);
        };

        float getAngOffset(){
            return getAngularOffset();
        };

    private:
        // ROS Variables
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_pub;
        rclcpp::Subscription<sensors::msg::ImuData>::SharedPtr imu_sub;
        rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr gps_sub;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr lidar_sub;
        rclcpp::Subscription<stereo::msg::Yolotag>::SharedPtr aruco_sub;
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr state_pub;

        bool search_pattern_flag = false;
        int search_pattern_function = 0;


        // Equation Constants

        std::vector<double> obs_avoid_linear;
        std::vector<double> obs_avoid_angular;
        std::vector<double> obj_follow_linear;
        std::vector<double> obj_follow_angular;
        std::vector<double> coord_follow_angular;
        std::vector<double> bearing_equation;

        // Velocity publisher variable

        geometry_msgs::msg::Twist velocity;

        // Sensor Data Variables

        double aruco_x = 100, aruco_y = 100, obs_x = 100, obs_y = 100;
        double current_orientation, dest_orientation, coordinate_bearing;
        double curr_time, temp_time;
        int time_offset=5;
        int count=0;
        Coordinates curr_location, dest_location;
        int goal_type;
        double dest_distance, bearing_angle;
        std::vector<float> lidar_samples;
        int lidar_center, lidar_min_range, lidar_max_range;
        int goal_count = 0;

        // Output Variables

        std::vector<double> output_velocity;
        std::map<int, Coordinates> obj_locations;

        // Truthtable select lines

        bool gps_coord_reached = false;
        bool aruco_detect = false;
        bool obstacle_detect = false;
        bool goal_reached = false;
        float angularOffset=90;

        // Rover state variables
        State CurrState;
        State PrevState;
        SearchPatternType FollowPattern = kPatternFollowing;

        // Returns a enum of rover state implementing the turth table below:
        // +========+=======+============+=======+===================+
        // | GPS    | Aruco |  Obstacle  | Goal  | State             |
        // +========+=======+============+=======+===================+
        // | 1      | 0     | 0          | 0     | GPS Following     |
        // | 0      | 0     | 0          | 0     | Search Pattern    |
        // | 0/1    | 1     | 0          | 0     | Aruco Following   |
        // | 0/1    | 0/1   | 1          | 0     | Obstacle Avoid    |
        // | 0/1    | 0/1   | 0/1        | 1     | Data Analysis     |
        // +--------+-------+------------+-------+-------------------+

        void RoverStateClassifier();

        // IMU Callback

        void imuCallback(const sensors::msg::ImuData::SharedPtr imu_msg);

        // GPS Callback

        void gpsCallback(const sensor_msgs::msg::NavSatFix::SharedPtr fix_);

        // LiDar Callback

        void lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr las);

        // Aruco Tag Detection Callback

        void arucoCallback(const stereo::msg::Yolotag::SharedPtr aruco);

        // void arucoYoloCallback(const stereo::yolotag::SharedPtr &msg);

        // Individual thread for publishing velocity based on the sensor data

        void stackRun();

        void publishVel(geometry_msgs::msg::Twist& msg);

        // Calling Search Pattern following function from controller class

        void callSearchPattern(SearchPatternType search_pattern_type);

        // Function to publish velocity for Obstacle Avoidance

        void obstacleAvoidance();

        // Function to publish velocity to Follow Objects

        void objectFollowing();

        // Function to publish velocity to follow GPS Coordinates

        void coordinateFollowing();

        // Set Search Pattern Flag

        void setSearchPatternFlag (bool a);

        // Get Searcg Pattern Flag
        
        bool getSearchPatternFlag ();

        std::vector<double> straightLineEquation(double x1, double y1, double x2, double y2);

        // Setters & Getters

        void setGPSStatus(bool status);

        void setArucoStatus(bool status);

        void setGoalStatus();

        State getState(bool current);

        bool getObstacleStatus();

        bool getGPSStatus();

        SearchPatternType getSearchPatternType();

        void setSearchPatternType(SearchPatternType state);

        void setAngularOffset(float offset);

        float getAngularOffset();

        // Call State Classifier function

        void callStateClassifier();

        // Returns the distance between two coordniates on the Earth

        double haversine(Coordinates curr, Coordinates dest);

        // Returns the bearing of the rover between two coordinates on the Earth

        void coordinateBearing();

        // Returns the least angle to travel between two IMU angles

        double bearing(double curr, double dest);

        // Sets the obstacle detected boolean of the Rover based on Lidar Data

        void obstacleClassifier();

        // Function for analysing arrow coordinates and actions after each sub-goal

        void dataAnalyzer();

        // Setting goal coordiantes for the task

        void getCoordinates();

        
    };

    // Function Definitons for State Classifier Class

    void SensorCallback::RoverStateClassifier()
    {
        
        if (goal_reached == true)
        {
            if (CurrState != kDataAnalysis)
                PrevState = CurrState;
            CurrState = kDataAnalysis;
            FollowPattern = kGoalCircle;
        }
        else if (obstacle_detect == true)
        {
            if (CurrState != kObstacleAvoidance)
                PrevState = CurrState;
            CurrState = kObstacleAvoidance;
        }
        else if (gps_coord_reached == false)
        {
            if (CurrState != kCoordinateFollowing)
                PrevState = CurrState;
            CurrState = kCoordinateFollowing;
        }
        else if (aruco_detect == true)
        {
            if (CurrState != kArucoFollowing)
                PrevState = CurrState;
            CurrState = kArucoFollowing;
        }
        else
        {
            if (CurrState != kSearchPattern)
                PrevState = CurrState;
            // angularOffset=15;            
            CurrState = kSearchPattern;
            if (FollowPattern != kTerminate)
                FollowPattern = kPatternFollowing;
        }
    };


    // Function Definitions for Sensor Interpreter Class

    void SensorCallback::setGPSStatus(bool status)
    {
        gps_coord_reached = status;
    };

    void SensorCallback::setArucoStatus(bool status)
    {
        aruco_detect = status;
    };

    void SensorCallback::setAngularOffset(float offset){
        angularOffset=offset;
    };

    float SensorCallback::getAngularOffset(){
        return angularOffset;
    };

    // void SensorCallback::setFollowPattern(State);
    void SensorCallback::setGoalStatus()
    {
        std_msgs::msg::Int32 msg;
        if (goal_type==1)
        {
            if (sqrt(pow(aruco_x, 2) + pow(aruco_y, 2)) <= 2)
            {
                if (goal_reached == false){
                    std::cout << sqrt(pow(aruco_x, 2) + pow(aruco_y, 2)) << std::endl;
                    RCLCPP_INFO(this->get_logger(),"ArUco Tag Reached");
                    // RCLCPP_INFO(this->get_logger(),"GOAL HAS BEEN REACHED!");
                }
                goal_reached = true;
                msg.data=2;
                for(int i=0;i<100;i++){
                    state_pub->publish(msg);
                }
            }
            else{
                goal_reached = false;
                msg.data=1;
                state_pub->publish(msg);
            }
        }
        else if (goal_type==0){
        
            if (getGPSStatus())
            {
                if (goal_reached == false){
                    std::cout <<dest_distance<< std::endl;
                    RCLCPP_INFO(this->get_logger(),"GPS Coordinate Reached");
                    // RCLCPP_INFO(this->get_logger(),"GOAL HAS BEEN REACHED!");
                }
                goal_reached = true;
                msg.data=2;
                for(int i=0;i<100;i++){
                    state_pub->publish(msg);
                }
            }
            else
            {
                goal_reached = false;
                msg.data=1;
                state_pub->publish(msg);
            }
        }
    }

    State SensorCallback::getState(bool curr)
    {
        if (curr == true)
            return CurrState;
        else
            return PrevState;
    };
    bool SensorCallback::getObstacleStatus()
    {
        return obstacle_detect;
    };

    bool SensorCallback::getGPSStatus()
    {
        return gps_coord_reached;
    };

    SearchPatternType SensorCallback::getSearchPatternType()
    {
        return FollowPattern;
    };

    void SensorCallback::setSearchPatternType(SearchPatternType state)
    {
        FollowPattern = state;
    };

    void SensorCallback::callStateClassifier()
    {
        RoverStateClassifier();
    }

    double SensorCallback::haversine(Coordinates curr, Coordinates dest)
    {
        double distance;
        double dLat = (dest.latitude - curr.latitude);
        double dLon = (dest.longitude - curr.longitude);
        double h = sin(dLat * 0.5) * sin(dLat * 0.5) + sin(dLon * 0.5) * sin(dLon * 5) * cos(curr.latitude * cos(dest.latitude));
        distance = asin(sqrt(h)) * 6367 * 2 * 1000;
        return distance;
    };

    void SensorCallback::coordinateBearing()
    {
        
        double dLon = (curr_location.longitude - dest_location.longitude);
        double y = sin(dLon) * cos(curr_location.latitude);
        double x = cos(dest_location.latitude) * sin(curr_location.latitude) - sin(dest_location.latitude) * cos(curr_location.latitude) * cos(dLon);
        double heading = atan2(y, x);
        if (heading < 0)
            heading = 2 * M_PI + heading;

        // Calculating bearing in -Pi to Pi form

        double orientation_radian = current_orientation * M_PI / 180;
        orientation_radian += 1.57;
        coordinate_bearing = heading - orientation_radian;

        if (coordinate_bearing > M_PI)
             coordinate_bearing = coordinate_bearing - 2 * M_PI;

        else if (coordinate_bearing < -M_PI)
             coordinate_bearing = coordinate_bearing + 2 * M_PI;

        std::cout<<"coordinate_bearing 2 : "<<coordinate_bearing<<std::endl;
    };

    double SensorCallback::bearing(double dest, double curr)
    {
        // current orientation ranges from -180 to 180 and destination orientation ranges from -180 to 180

        if (dest - curr > 180)
            return -(360 - (dest - curr));
        else if (dest - curr > 0)
            return (dest - curr);
        else if (dest - curr < -180)
            return (360 - abs(dest - curr));
        else
            return -(dest - curr);
    };

    void SensorCallback::obstacleClassifier()
    {
        // Variable Definiton

        float min_value = kMaxObsThreshold;
        double temp_angle = 0;
        int temp_sample = 0;

        // Finding obstacle in the given range and calcualting its coordinates wrt Lidar
        
        for (int i = lidar_min_range; i <= lidar_max_range; i++)
        {
            if (lidar_samples[i] <= min_value && lidar_samples[i] > kMinObsThreshold)
            {
                temp_sample = i;
                min_value = lidar_samples[temp_sample];
            }
        }
        temp_angle = abs(lidar_center - temp_sample) * kLidarAngularRange / kLidarSamples;
        obs_x = min_value * cos(temp_angle * M_PI / 180);
        obs_y = min_value * sin(temp_angle * M_PI / 180);
        if(lidar_center < temp_sample)
            obs_y = -obs_y;

        // Classifying if obstacle is in path

        // If aruco is detected as obstacle

        if (aruco_detect == true && abs(obs_x - aruco_x) < 0.3 && abs(obs_y - aruco_y) < 0.3)
        {
            obstacle_detect = false;
            return;
        }

        // If obstacle is in the path of the rover

        if (min_value < kMaxObsThreshold && min_value > kMinObsThreshold)
            obstacle_detect = true;
        else
            obstacle_detect = false;
    };

    void SensorCallback::dataAnalyzer()
    {   

        if (PrevState == kArucoFollowing)
        {
            RCLCPP_INFO(this->get_logger(),"Goal Reached!");
            RCLCPP_INFO(this->get_logger(),"Checking for similar coordinates...");

            std::map<int, Coordinates>::iterator it = obj_locations.begin();
            bool same_coord = false;

            while (it != obj_locations.end())
            {
                Coordinates temp = it->second;
                double distance =  haversine(temp, curr_location);
                if (distance < 3)
                {
                    same_coord = true;
                    RCLCPP_INFO(this->get_logger(),"Duplicate Object detected going back to GPS Coordinate...");
                    dest_distance =  haversine(curr_location, dest_location);
                    if (getGPSStatus() == false && dest_distance > 2)
                        setGPSStatus(false);
                    else if (getGPSStatus() == false && dest_distance < 2)
                        setGPSStatus(true);
                    return;
                }
            }
            if (same_coord == false)
            {
                goal_count++;
                RCLCPP_INFO(this->get_logger(),"Unique Object found! Saving to map and updating CSV");
                obj_locations.insert(std::pair<int, Coordinates>(obj_locations.size() + 1, curr_location));

                
                RCLCPP_INFO(this->get_logger(),"Flashing green light...");
                
                // TODO(Saatwik): setup green light flashing publish message

                std::this_thread::sleep_for(std::chrono::seconds(5));

                // setGPSStatus(false);
                // getCoordinates();
                exit(0);
            }
        }

        else if (PrevState == kCoordinateFollowing)
        {
            RCLCPP_INFO(this->get_logger(),"Coordinate Reached!");      
            goal_count++;
   
            RCLCPP_INFO(this->get_logger(),"Flashing green light...");
                
            // TODO(Saatwik): setup green light flashing publish message

            std::this_thread::sleep_for(std::chrono::seconds(5));

            // getCoordinates();
            exit(0);
        }
    };

    // Setting goal coordiantes for the task

    void SensorCallback::getCoordinates()
    {
        RCLCPP_INFO(this->get_logger(),"Enter Latitude and Longitude of the goal:");
        std::cin >> dest_location.latitude >> dest_location.longitude;
        RCLCPP_INFO(this->get_logger(),"Enter type of the goal (0 for gps 1 for object): ");
        std::cin >> goal_type;
        // if (dest_location.latitude == 0 && dest_location.longitude == 0)
        //     RCLCPP_INFO(this->get_logger(),"Task Completed.");
        dest_location.latitude = dest_location.latitude * M_PI / 180;
        dest_location.longitude = dest_location.longitude * M_PI / 180;
        setGPSStatus(false);
        // setSearchPatternType(kTerminate);
    };

    // Function Definitions for Sensor Callback Class

    void SensorCallback::imuCallback(const sensors::msg::ImuData::SharedPtr imu_msg)
    {
        current_orientation = imu_msg->orientation.z;
    };

    void SensorCallback::gpsCallback(const sensor_msgs::msg::NavSatFix::SharedPtr fix_)
    {
        curr_location.latitude = fix_->latitude * M_PI / 180;
        curr_location.longitude = fix_->longitude * M_PI / 180;

        // Calulating distance using Haversine formula

        dest_distance =  haversine(curr_location, dest_location);
        
        // RCLCPP_INFO(this->get_logger(),getGPSStatus());
        // RCLCPP_INFO(this->get_logger(),dest_distance);

        // Calculating heading to travel

        coordinateBearing();

        if (getGPSStatus() == false && dest_distance > 2)
            setGPSStatus(false);

        else if (getGPSStatus() == false && dest_distance < 2)
            setGPSStatus(true);
        // else if (getGPSStatus() == true && dest_distance > 2)
        //     setGPSStatus(false);

        else if(goal_type==1 && getGPSStatus() == true && dest_distance > 50)
        {
            RCLCPP_INFO(this->get_logger(),"Search Pattern did not find Aruco Markers");
            RCLCPP_INFO(this->get_logger(),"Returning to GPS Coordinate...");
            time_offset=5;
            setGPSStatus(false);
        }
    };

    void SensorCallback::lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr las)
    {
        lidar_samples = las->ranges;
        obstacleClassifier();
        if (getObstacleStatus() == true)
            search_pattern_function = 0;
        stackRun();
    };

    void SensorCallback::arucoCallback(const stereo::msg::Yolotag::SharedPtr aruco)
    {
        // RCLCPP_INFO(this->get_logger(),"%d",aruco->isFound);
        if (aruco->is_found == true)
        {
            search_pattern_function = 0;
            aruco_x = aruco->x;
            aruco_y = aruco->y;
            setArucoStatus(true);
        }
        else
        {
            setArucoStatus(false);
            aruco_x = 100;
            aruco_y = 100;
        }
    };

    void SensorCallback::stackRun()
    {
        setGoalStatus();

        callStateClassifier();
        
        // std::cout<<"State: "<<getState(true)<<std::endl;

        if (search_pattern_flag == false)
        {
            
            switch (getState(true))
            {

                // Function to Analyze data when rover reaches Aruco Tag

            case kDataAnalysis:
                velocity.linear.x = 0;
                velocity.angular.z = 0;
                publishVel(velocity);
                dataAnalyzer();
                if(goal_type!=0)
                    callSearchPattern(getSearchPatternType());
                break;

                // Function to publish velocity when in Aurco Tag Following

            case kArucoFollowing:
                objectFollowing();
                break;

                // Function to publish velocity when in Obstacle Avoidance

            case kObstacleAvoidance:
                obstacleAvoidance();
                break;
                // Function to publish velocity when following GPS Coordinate

            case kCoordinateFollowing:
                coordinateFollowing();
                break;

                // Function to Follow Search Pattern

            case kSearchPattern:
                callSearchPattern(getSearchPatternType());
                break;
            }
        }

        else if (getState(true) == kCoordinateFollowing)
            coordinateFollowing();
        else
            callSearchPattern(getSearchPatternType());
    };

    // Function Definitons for Equation Generator Class
    void SensorCallback::publishVel(geometry_msgs::msg::Twist& msg)
    {
        if (msg.linear.x<0)
        {
            msg.linear.x=0;
        }
        vel_pub->publish(msg);
    };
    
    std::vector<double> SensorCallback::straightLineEquation(double x1, double y1, double x2, double y2)
    {
        std::vector<double> temp;

        double m = (y2 - y1) / (x2 - x1);
        double c = -((y2 - y2) / (x2 - x1) * x1) + y1;

        temp.push_back(m);
        temp.push_back(c);

        return temp;
    };

    // Function Definitons for Search Pattern Class

    // geometry_msgs::Twist SearchPattern::hardTurn(double time){};

    // geometry_msgs::Twist SearchPattern::moveForward(double time){};

    // Function Definition for Controller Class

    void SensorCallback::callSearchPattern(SearchPatternType search_pattern_type)
    {
        switch (search_pattern_type)
        {

        case kGoalCircle:
            if (getSearchPatternFlag() == false)
            {
                RCLCPP_INFO(this->get_logger(),"Turning 90 Degrees Right..");
                // curr_time = this->now().seconds();;
                // temp_time = (ros::Time::now() + ros::Duration(100)).toSec();
                setSearchPatternFlag(true);
                dest_orientation = current_orientation + 90;
                if (dest_orientation > 360)
                    dest_orientation = 360 - dest_orientation;
                bearing_equation = straightLineEquation(90, kMaxAngularVel, 0, 0);
            }
            else
            {
                curr_time = this->now().seconds();;
                if (abs(bearing(dest_orientation, current_orientation)) < 5)
                {
                    RCLCPP_INFO(this->get_logger(),"Turning Complete...");
                    // RCLCPP_INFO(this->get_logger(),"Moving in a Circle...");
                    setSearchPatternFlag(false);
                    // temp_time = (ros::Time::now() + ros::Duration(20)).toSec();
                    velocity.linear.x = 0;
                    velocity.angular.z = 0;
                    publishVel(velocity);
                }
                else if (abs(bearing(dest_orientation, current_orientation)) > 5)
                {
                    velocity.linear.x = 0;
                    velocity.angular.z = -(abs(bearing(dest_orientation, current_orientation)) * bearing_equation[0] + bearing_equation[1]);
                    publishVel(velocity);
                }
            }
            break;
        case kPatternFollowing:
            switch (search_pattern_function)
            {
            case 0:
                RCLCPP_INFO(this->get_logger(),"Starting Search Pattern: Moving Forward...");
                curr_time = this->now().seconds();;
                // time_offset;
                
                RCLCPP_INFO(this->get_logger(),"time now %d", time_offset);
                     
                temp_time = (this->get_clock()->now() + rclcpp::Duration::from_seconds(time_offset)).seconds();

                search_pattern_function = 1;
                break;
            case 1:
                curr_time = this->now().seconds();;
                if (temp_time >= curr_time)
                {
                    velocity.linear.x = kMaxLinearVel;
                    velocity.angular.z = 0;
                    publishVel(velocity);
                }
                else
                {
                    RCLCPP_INFO(this->get_logger(),"Search Pattern: Hard Turning Right");
                    dest_orientation = current_orientation + 135;
                    if (dest_orientation > 360)
                        dest_orientation = dest_orientation - 360;
                    search_pattern_function = 2;
                    velocity.linear.x = 0;
                    velocity.angular.z = 0;
                    publishVel(velocity);
                    bearing_equation = straightLineEquation(135, kMaxAngularVel, 0, 0);
                }
                break;
            case 2:
                if (abs(bearing(dest_orientation, current_orientation)) > 5)
                {
                    velocity.linear.x = 0;
                    velocity.angular.z = -(abs(bearing(dest_orientation, current_orientation)) * bearing_equation[0] + bearing_equation[1]);
                    publishVel(velocity);
                }
                else
                {

                    RCLCPP_INFO(this->get_logger(),"No Aruco Tag found on the Right...");
                    RCLCPP_INFO(this->get_logger(),"Search Pattern: Hard Turning Left");
                    dest_orientation = current_orientation + 90;
                    if (dest_orientation > 360)
                        dest_orientation = dest_orientation - 360;
                    search_pattern_function = 3;
                    velocity.linear.x = 0;
                    velocity.angular.z = 0;
                    publishVel(velocity);
                    bearing_equation = straightLineEquation(270, kMaxAngularVel, 0, 0);
                }
                break;
            case 3:
                if (abs(bearing(dest_orientation, current_orientation)) > 5)
                {
                    velocity.linear.x = 0;
                    velocity.angular.z = (abs(bearing(dest_orientation, current_orientation)) * bearing_equation[0] + bearing_equation[1]);
                    publishVel(velocity);
                }
                else
                {
                    RCLCPP_INFO(this->get_logger(),"No Aruco found on the Left...");
                    RCLCPP_INFO(this->get_logger(),"Adding an offset...");
                    dest_orientation = current_orientation + 135 + getAngOffset();
                    count++;
                    RCLCPP_INFO(this->get_logger(),"count %d",count);
                    if (count==5){
                        count=0;
                        time_offset+=10;
                    }
                    // dest_orientation = current_orientation + 135;
                    if (dest_orientation > 360)
                        dest_orientation = dest_orientation - 360;
                    search_pattern_function = 4;
                    velocity.linear.x = 0;
                    velocity.angular.z = 0;
                    publishVel(velocity);
                    bearing_equation = straightLineEquation(135, kMaxAngularVel, 0, 0);
                }
                break;
            case 4:
                if (abs(bearing(dest_orientation, current_orientation)) > 5)
                {
                    velocity.linear.x = 0;
                    velocity.angular.z = -(abs(bearing(dest_orientation, current_orientation)) * bearing_equation[0] + bearing_equation[1]);
                    publishVel(velocity);
                }
                else
                {
                    RCLCPP_INFO(this->get_logger(),"Offset Reached...");
                    RCLCPP_INFO(this->get_logger(),"'%f'",getAngOffset());
                    setAngOffset(getAngOffset());
                    search_pattern_function = 0;
                    velocity.linear.x = 0;
                    velocity.angular.z = 0;
                    publishVel(velocity);
                }
                break;
            }
            break;
        case kTerminate:
            setSearchPatternFlag(false);
            velocity.linear.x = 0;
            velocity.angular.z = 0;
            publishVel(velocity);
            // exit(0);
            break;
        }
    };

    void SensorCallback::obstacleAvoidance()
    {
        // RCLCPP_INFO(this->get_logger(),"here");
          
        velocity.linear.x = 0;//obs_avoid_linear[0] * obs_x + obs_avoid_linear[1];

        if(obs_y <= 0)
            velocity.angular.z = -0.8;//obs_avoid_angular[0] * abs(obs_y) + obs_avoid_angular[1];
        else
            velocity.angular.z = 0.8;//(obs_avoid_angular[0] * abs(obs_y) + obs_avoid_angular[1]);
        publishVel(velocity);
    };
    void SensorCallback::objectFollowing()
    {
        if (aruco_x >= 2)
            velocity.linear.x = kMaxLinearVel*0.8;
        else
            velocity.linear.x = obj_follow_linear[0] * aruco_x + obj_follow_linear[1];
        if (aruco_y >= 2)
            velocity.angular.z = -kMaxAngularVel;
        else if (aruco_y < -2)
            velocity.angular.z = kMaxAngularVel;
        else if (aruco_y > 0)
            velocity.angular.z = -(obj_follow_angular[0] * abs(aruco_y) + obj_follow_angular[1]);
        else if (aruco_y < 0)
            velocity.angular.z = obj_follow_angular[0] * abs(aruco_y) + obj_follow_angular[1];
        publishVel(velocity);
    };
    void SensorCallback::coordinateFollowing()
    {
        // std::cout<<"Heading: "<<heading<<std::endl;
        // std::cout<<"orientation_radian: "<<orientation_radian<<std::endl;
        std::cout<<"coordinate_bearing: "<<coordinate_bearing<<std::endl;
        std::cout<<"distance: "<<dest_distance<<std::endl;

        // if (dest_distance > 5)
        //         velocity.linear.x = (kMaxLinearVel*2) / M_PI_2 * pow((abs(coordinate_bearing) - M_PI_2), 2);



        if ((coordinate_bearing) < -M_PI + 0.3 || (coordinate_bearing) > M_PI - 0.3)

            {RCLCPP_INFO(this->get_logger(),"jfikadfbiasf");
            velocity.linear.x = kMaxLinearVel*1.5; 
            velocity.angular.z=0.0;}
        else
            velocity.angular.z = 0.75;//kMaxAngularVel/2 * pow(coordinate_bearing, 2) / pow(M_PI_2, 2);


        if (dest_distance <= 5)
            velocity.linear.x = 0.5;// * pow(dest_distance, 2) / pow(M_PI_2, 2);
        
        if (dest_distance <= 2)
            velocity.linear.x = 0;

        if (coordinate_bearing < 0)
            velocity.angular.z = -velocity.angular.z;
        else if (coordinate_bearing >= 0)
            velocity.angular.z = velocity.angular.z;
    	 publishVel(velocity);
    };
    void SensorCallback::setSearchPatternFlag (bool flag)
    {
        search_pattern_flag = flag;
    };
    bool SensorCallback::getSearchPatternFlag()
    {
        return search_pattern_flag;
    };
}
#endif