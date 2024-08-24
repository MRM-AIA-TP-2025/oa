// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensors:msg/NavigationData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__NAVIGATION_DATA__TRAITS_HPP_
#define SENSORS__MSG__DETAIL__NAVIGATION_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sensors/msg/detail/navigation_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sensors
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavigationData & msg,
  std::ostream & out)
{
  out << "{";
  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: bearing
  {
    out << "bearing: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing, out);
    out << ", ";
  }

  // member: orientation
  {
    out << "orientation: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation, out);
    out << ", ";
  }

  // member: isonline
  {
    out << "isonline: ";
    rosidl_generator_traits::value_to_yaml(msg.isonline, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigationData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: bearing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bearing: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing, out);
    out << "\n";
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation, out);
    out << "\n";
  }

  // member: isonline
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "isonline: ";
    rosidl_generator_traits::value_to_yaml(msg.isonline, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigationData & msg, bool use_flow_style = false)
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
  const sensors::msg::NavigationData & msg,
  std::ostream & out, size_t indentation = 0)
{
  sensors::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sensors::msg::to_yaml() instead")]]
inline std::string to_yaml(const sensors::msg::NavigationData & msg)
{
  return sensors::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sensors::msg::NavigationData>()
{
  return "sensors::msg::NavigationData";
}

template<>
inline const char * name<sensors::msg::NavigationData>()
{
  return "sensors/msg/NavigationData";
}

template<>
struct has_fixed_size<sensors::msg::NavigationData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sensors::msg::NavigationData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sensors::msg::NavigationData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SENSORS__MSG__DETAIL__NAVIGATION_DATA__TRAITS_HPP_
