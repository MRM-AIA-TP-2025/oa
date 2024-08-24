// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensors:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__IMU_DATA__TRAITS_HPP_
#define SENSORS__MSG__DETAIL__IMU_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sensors/msg/detail/imu_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'acceleration'
// Member 'orientation'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace sensors
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImuData & msg,
  std::ostream & out)
{
  out << "{";
  // member: acceleration
  {
    out << "acceleration: ";
    to_flow_style_yaml(msg.acceleration, out);
    out << ", ";
  }

  // member: orientation
  {
    out << "orientation: ";
    to_flow_style_yaml(msg.orientation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration:\n";
    to_block_style_yaml(msg.acceleration, out, indentation + 2);
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation:\n";
    to_block_style_yaml(msg.orientation, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImuData & msg, bool use_flow_style = false)
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
  const sensors::msg::ImuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  sensors::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sensors::msg::to_yaml() instead")]]
inline std::string to_yaml(const sensors::msg::ImuData & msg)
{
  return sensors::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sensors::msg::ImuData>()
{
  return "sensors::msg::ImuData";
}

template<>
inline const char * name<sensors::msg::ImuData>()
{
  return "sensors/msg/ImuData";
}

template<>
struct has_fixed_size<sensors::msg::ImuData>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<sensors::msg::ImuData>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<sensors::msg::ImuData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SENSORS__MSG__DETAIL__IMU_DATA__TRAITS_HPP_
