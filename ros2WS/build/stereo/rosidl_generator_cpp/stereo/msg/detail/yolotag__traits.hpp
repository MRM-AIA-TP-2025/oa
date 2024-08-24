// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stereo:msg/Yolotag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__YOLOTAG__TRAITS_HPP_
#define STEREO__MSG__DETAIL__YOLOTAG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stereo/msg/detail/yolotag__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace stereo
{

namespace msg
{

inline void to_flow_style_yaml(
  const Yolotag & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_found
  {
    out << "is_found: ";
    rosidl_generator_traits::value_to_yaml(msg.is_found, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Yolotag & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_found: ";
    rosidl_generator_traits::value_to_yaml(msg.is_found, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Yolotag & msg, bool use_flow_style = false)
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

}  // namespace stereo

namespace rosidl_generator_traits
{

[[deprecated("use stereo::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stereo::msg::Yolotag & msg,
  std::ostream & out, size_t indentation = 0)
{
  stereo::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stereo::msg::to_yaml() instead")]]
inline std::string to_yaml(const stereo::msg::Yolotag & msg)
{
  return stereo::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stereo::msg::Yolotag>()
{
  return "stereo::msg::Yolotag";
}

template<>
inline const char * name<stereo::msg::Yolotag>()
{
  return "stereo/msg/Yolotag";
}

template<>
struct has_fixed_size<stereo::msg::Yolotag>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<stereo::msg::Yolotag>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<stereo::msg::Yolotag>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STEREO__MSG__DETAIL__YOLOTAG__TRAITS_HPP_
