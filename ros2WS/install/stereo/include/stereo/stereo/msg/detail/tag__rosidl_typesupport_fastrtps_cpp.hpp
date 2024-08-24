// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from stereo:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__TAG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define STEREO__MSG__DETAIL__TAG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "stereo/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "stereo/msg/detail/tag__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace stereo
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stereo
cdr_serialize(
  const stereo::msg::Tag & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stereo
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  stereo::msg::Tag & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stereo
get_serialized_size(
  const stereo::msg::Tag & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stereo
max_serialized_size_Tag(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace stereo

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stereo
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, stereo, msg, Tag)();

#ifdef __cplusplus
}
#endif

#endif  // STEREO__MSG__DETAIL__TAG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
