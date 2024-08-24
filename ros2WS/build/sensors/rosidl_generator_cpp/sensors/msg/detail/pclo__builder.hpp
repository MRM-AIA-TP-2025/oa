// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sensors:msg/Pclo.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__PCLO__BUILDER_HPP_
#define SENSORS__MSG__DETAIL__PCLO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sensors/msg/detail/pclo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sensors
{

namespace msg
{

namespace builder
{

class Init_Pclo_right
{
public:
  explicit Init_Pclo_right(::sensors::msg::Pclo & msg)
  : msg_(msg)
  {}
  ::sensors::msg::Pclo right(::sensors::msg::Pclo::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sensors::msg::Pclo msg_;
};

class Init_Pclo_left
{
public:
  explicit Init_Pclo_left(::sensors::msg::Pclo & msg)
  : msg_(msg)
  {}
  Init_Pclo_right left(::sensors::msg::Pclo::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_Pclo_right(msg_);
  }

private:
  ::sensors::msg::Pclo msg_;
};

class Init_Pclo_front
{
public:
  Init_Pclo_front()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pclo_left front(::sensors::msg::Pclo::_front_type arg)
  {
    msg_.front = std::move(arg);
    return Init_Pclo_left(msg_);
  }

private:
  ::sensors::msg::Pclo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sensors::msg::Pclo>()
{
  return sensors::msg::builder::Init_Pclo_front();
}

}  // namespace sensors

#endif  // SENSORS__MSG__DETAIL__PCLO__BUILDER_HPP_
