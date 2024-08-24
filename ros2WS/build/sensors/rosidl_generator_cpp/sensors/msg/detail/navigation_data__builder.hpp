// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sensors:msg/NavigationData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__NAVIGATION_DATA__BUILDER_HPP_
#define SENSORS__MSG__DETAIL__NAVIGATION_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sensors/msg/detail/navigation_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sensors
{

namespace msg
{

namespace builder
{

class Init_NavigationData_isonline
{
public:
  explicit Init_NavigationData_isonline(::sensors::msg::NavigationData & msg)
  : msg_(msg)
  {}
  ::sensors::msg::NavigationData isonline(::sensors::msg::NavigationData::_isonline_type arg)
  {
    msg_.isonline = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sensors::msg::NavigationData msg_;
};

class Init_NavigationData_orientation
{
public:
  explicit Init_NavigationData_orientation(::sensors::msg::NavigationData & msg)
  : msg_(msg)
  {}
  Init_NavigationData_isonline orientation(::sensors::msg::NavigationData::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_NavigationData_isonline(msg_);
  }

private:
  ::sensors::msg::NavigationData msg_;
};

class Init_NavigationData_bearing
{
public:
  explicit Init_NavigationData_bearing(::sensors::msg::NavigationData & msg)
  : msg_(msg)
  {}
  Init_NavigationData_orientation bearing(::sensors::msg::NavigationData::_bearing_type arg)
  {
    msg_.bearing = std::move(arg);
    return Init_NavigationData_orientation(msg_);
  }

private:
  ::sensors::msg::NavigationData msg_;
};

class Init_NavigationData_distance
{
public:
  Init_NavigationData_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationData_bearing distance(::sensors::msg::NavigationData::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_NavigationData_bearing(msg_);
  }

private:
  ::sensors::msg::NavigationData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sensors::msg::NavigationData>()
{
  return sensors::msg::builder::Init_NavigationData_distance();
}

}  // namespace sensors

#endif  // SENSORS__MSG__DETAIL__NAVIGATION_DATA__BUILDER_HPP_
