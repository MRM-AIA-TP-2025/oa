cmake_minimum_required(VERSION 3.8)
project(zed2cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL REQUIRED COMPONENTS common io filters segmentation)
find_package(sensors REQUIRED)  # Make sure your custom message package is found
find_package(geometry_msgs REQUIRED)

# Include directories
include_directories(
  include
  ${PCL_INCLUDE_DIRS}
)

# Add executable for pcloa
add_executable(pcloa src/pcloa.cpp)
ament_target_dependencies(pcloa rclcpp sensor_msgs pcl_conversions PCL sensors)  # Add sensors if needed

# Add executable for nav
add_executable(nav src/navigation.cpp)
ament_target_dependencies(nav rclcpp sensor_msgs sensors geometry_msgs)

add_executable(navdata src/navdata.cpp)
ament_target_dependencies(navdata rclcpp sensor_msgs sensors geometry_msgs)

# Link libraries
target_link_libraries(pcloa ${PCL_LIBRARIES})

# Remove incorrect target_link_libraries usage for nav
# target_link_libraries(nav
#   sensors::msg::NavigationData
#   sensors::msg::Pclo
# )

# Install targets
install(TARGETS
  pcloa
  nav
  navdata
  DESTINATION lib/${PROJECT_NAME}
)

# ament package
ament_package()
