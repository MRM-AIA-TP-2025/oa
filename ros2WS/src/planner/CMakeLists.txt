cmake_minimum_required(VERSION 3.8)
project(planner)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensors REQUIRED)  # Find the sensors package to use its messages
find_package(rosidl_default_generators REQUIRED)  # Required for custom message dependencies
find_package(stereo REQUIRED) 
# Include directories
include_directories(
  include
)

# Add executables
add_executable(planner src/planner.cpp src/include/planner.hpp)
add_executable(imu_convert src/imu_converter.cpp)
# Link libraries
ament_target_dependencies(planner
  rclcpp
  sensor_msgs
  geometry_msgs
  sensors
  std_msgs
  stereo  # Link against the sensors package
)
ament_target_dependencies(imu_convert
  rclcpp
  tf2
  tf2_geometry_msgs
  sensor_msgs
  geometry_msgs
  sensors  # Link against the sensors package
)
install(DIRECTORY 
  DESTINATION share/${PROJECT_NAME}
)

# Install
install(TARGETS
  planner
  imu_convert
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
