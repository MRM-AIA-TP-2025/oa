// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stereo:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__TAG__BUILDER_HPP_
#define STEREO__MSG__DETAIL__TAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stereo/msg/detail/tag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stereo
{

namespace msg
{

namespace builder
{

class Init_Tag_id
{
public:
  explicit Init_Tag_id(::stereo::msg::Tag & msg)
  : msg_(msg)
  {}
  ::stereo::msg::Tag id(::stereo::msg::Tag::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stereo::msg::Tag msg_;
};

class Init_Tag_y
{
public:
  explicit Init_Tag_y(::stereo::msg::Tag & msg)
  : msg_(msg)
  {}
  Init_Tag_id y(::stereo::msg::Tag::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Tag_id(msg_);
  }

private:
  ::stereo::msg::Tag msg_;
};

class Init_Tag_x
{
public:
  explicit Init_Tag_x(::stereo::msg::Tag & msg)
  : msg_(msg)
  {}
  Init_Tag_y x(::stereo::msg::Tag::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Tag_y(msg_);
  }

private:
  ::stereo::msg::Tag msg_;
};

class Init_Tag_is_found
{
public:
  Init_Tag_is_found()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tag_x is_found(::stereo::msg::Tag::_is_found_type arg)
  {
    msg_.is_found = std::move(arg);
    return Init_Tag_x(msg_);
  }

private:
  ::stereo::msg::Tag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stereo::msg::Tag>()
{
  return stereo::msg::builder::Init_Tag_is_found();
}

}  // namespace stereo

#endif  // STEREO__MSG__DETAIL__TAG__BUILDER_HPP_
