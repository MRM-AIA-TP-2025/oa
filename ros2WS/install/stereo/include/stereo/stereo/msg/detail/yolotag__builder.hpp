// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stereo:msg/Yolotag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__YOLOTAG__BUILDER_HPP_
#define STEREO__MSG__DETAIL__YOLOTAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stereo/msg/detail/yolotag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stereo
{

namespace msg
{

namespace builder
{

class Init_Yolotag_id
{
public:
  explicit Init_Yolotag_id(::stereo::msg::Yolotag & msg)
  : msg_(msg)
  {}
  ::stereo::msg::Yolotag id(::stereo::msg::Yolotag::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stereo::msg::Yolotag msg_;
};

class Init_Yolotag_y
{
public:
  explicit Init_Yolotag_y(::stereo::msg::Yolotag & msg)
  : msg_(msg)
  {}
  Init_Yolotag_id y(::stereo::msg::Yolotag::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Yolotag_id(msg_);
  }

private:
  ::stereo::msg::Yolotag msg_;
};

class Init_Yolotag_x
{
public:
  explicit Init_Yolotag_x(::stereo::msg::Yolotag & msg)
  : msg_(msg)
  {}
  Init_Yolotag_y x(::stereo::msg::Yolotag::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Yolotag_y(msg_);
  }

private:
  ::stereo::msg::Yolotag msg_;
};

class Init_Yolotag_is_found
{
public:
  Init_Yolotag_is_found()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Yolotag_x is_found(::stereo::msg::Yolotag::_is_found_type arg)
  {
    msg_.is_found = std::move(arg);
    return Init_Yolotag_x(msg_);
  }

private:
  ::stereo::msg::Yolotag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stereo::msg::Yolotag>()
{
  return stereo::msg::builder::Init_Yolotag_is_found();
}

}  // namespace stereo

#endif  // STEREO__MSG__DETAIL__YOLOTAG__BUILDER_HPP_
