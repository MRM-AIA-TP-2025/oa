// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensors:msg/Pclo.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__PCLO__TRAITS_HPP_
#define SENSORS__MSG__DETAIL__PCLO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sensors/msg/detail/pclo__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sensors
{

namespace msg
{

inline void to_flow_style_yaml(
  const Pclo & msg,
  std::ostream & out)
{
  out << "{";
  // member: front
  {
    out << "front: ";
    rosidl_generator_traits::value_to_yaml(msg.front, out);
    out << ", ";
  }

  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pclo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: front
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front: ";
    rosidl_generator_traits::value_to_yaml(msg.front, out);
    out << "\n";
  }

  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pclo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace sensors

namespace rosidl_generator_traits
{

[[deprecated("use sensors::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sensors::msg::Pclo & msg,
  std::ostream & out, size_t indentation = 0)
{
  sensors::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sensors::msg::to_yaml() instead")]]
inline std::string to_yaml(const sensors::msg::Pclo & msg)
{
  return sensors::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sensors::msg::Pclo>()
{
  return "sensors::msg::Pclo";
}

template<>
inline const char * name<sensors::msg::Pclo>()
{
  return "sensors/msg/Pclo";
}

template<>
struct has_fixed_size<sensors::msg::Pclo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sensors::msg::Pclo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sensors::msg::Pclo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SENSORS__MSG__DETAIL__PCLO__TRAITS_HPP_
