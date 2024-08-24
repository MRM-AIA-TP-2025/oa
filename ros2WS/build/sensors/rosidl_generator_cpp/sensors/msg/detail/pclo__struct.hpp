// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sensors:msg/Pclo.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__PCLO__STRUCT_HPP_
#define SENSORS__MSG__DETAIL__PCLO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sensors__msg__Pclo __attribute__((deprecated))
#else
# define DEPRECATED__sensors__msg__Pclo __declspec(deprecated)
#endif

namespace sensors
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pclo_
{
  using Type = Pclo_<ContainerAllocator>;

  explicit Pclo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front = false;
      this->left = false;
      this->right = false;
    }
  }

  explicit Pclo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front = false;
      this->left = false;
      this->right = false;
    }
  }

  // field types and members
  using _front_type =
    bool;
  _front_type front;
  using _left_type =
    bool;
  _left_type left;
  using _right_type =
    bool;
  _right_type right;

  // setters for named parameter idiom
  Type & set__front(
    const bool & _arg)
  {
    this->front = _arg;
    return *this;
  }
  Type & set__left(
    const bool & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__right(
    const bool & _arg)
  {
    this->right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sensors::msg::Pclo_<ContainerAllocator> *;
  using ConstRawPtr =
    const sensors::msg::Pclo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sensors::msg::Pclo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sensors::msg::Pclo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sensors::msg::Pclo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sensors::msg::Pclo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sensors::msg::Pclo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sensors::msg::Pclo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sensors::msg::Pclo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sensors::msg::Pclo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sensors__msg__Pclo
    std::shared_ptr<sensors::msg::Pclo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sensors__msg__Pclo
    std::shared_ptr<sensors::msg::Pclo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pclo_ & other) const
  {
    if (this->front != other.front) {
      return false;
    }
    if (this->left != other.left) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pclo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pclo_

// alias to use template instance with default allocator
using Pclo =
  sensors::msg::Pclo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sensors

#endif  // SENSORS__MSG__DETAIL__PCLO__STRUCT_HPP_
