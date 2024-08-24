// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stereo:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__TAG__STRUCT_HPP_
#define STEREO__MSG__DETAIL__TAG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__stereo__msg__Tag __attribute__((deprecated))
#else
# define DEPRECATED__stereo__msg__Tag __declspec(deprecated)
#endif

namespace stereo
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Tag_
{
  using Type = Tag_<ContainerAllocator>;

  explicit Tag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_found = false;
      this->x = 0.0;
      this->y = 0.0;
      this->id = 0ll;
    }
  }

  explicit Tag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_found = false;
      this->x = 0.0;
      this->y = 0.0;
      this->id = 0ll;
    }
  }

  // field types and members
  using _is_found_type =
    bool;
  _is_found_type is_found;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _id_type =
    int64_t;
  _id_type id;

  // setters for named parameter idiom
  Type & set__is_found(
    const bool & _arg)
  {
    this->is_found = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__id(
    const int64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stereo::msg::Tag_<ContainerAllocator> *;
  using ConstRawPtr =
    const stereo::msg::Tag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stereo::msg::Tag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stereo::msg::Tag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stereo::msg::Tag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stereo::msg::Tag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stereo::msg::Tag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stereo::msg::Tag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stereo::msg::Tag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stereo::msg::Tag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stereo__msg__Tag
    std::shared_ptr<stereo::msg::Tag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stereo__msg__Tag
    std::shared_ptr<stereo::msg::Tag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Tag_ & other) const
  {
    if (this->is_found != other.is_found) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Tag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Tag_

// alias to use template instance with default allocator
using Tag =
  stereo::msg::Tag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stereo

#endif  // STEREO__MSG__DETAIL__TAG__STRUCT_HPP_
