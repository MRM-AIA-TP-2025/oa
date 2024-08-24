// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sensors:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
#define SENSORS__MSG__DETAIL__IMU_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sensors/msg/detail/imu_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sensors
{

namespace msg
{

namespace builder
{

class Init_ImuData_orientation
{
public:
  explicit Init_ImuData_orientation(::sensors::msg::ImuData & msg)
  : msg_(msg)
  {}
  ::sensors::msg::ImuData orientation(::sensors::msg::ImuData::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sensors::msg::ImuData msg_;
};

class Init_ImuData_acceleration
{
public:
  Init_ImuData_acceleration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuData_orientation acceleration(::sensors::msg::ImuData::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_ImuData_orientation(msg_);
  }

private:
  ::sensors::msg::ImuData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sensors::msg::ImuData>()
{
  return sensors::msg::builder::Init_ImuData_acceleration();
}

}  // namespace sensors

#endif  // SENSORS__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
