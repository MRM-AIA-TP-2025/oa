cmake_minimum_required(VERSION 3.8)
project(stereo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(Python3 REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development)

# Declare the message files
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Tag.msg"
  "msg/Yolotag.msg"
  DEPENDENCIES std_msgs
)

# Export the necessary dependencies
ament_export_dependencies(rosidl_default_runtime)

# Install Python scripts




ament_package()
