// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sensors:msg/NavigationData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__NAVIGATION_DATA__STRUCT_HPP_
#define SENSORS__MSG__DETAIL__NAVIGATION_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sensors__msg__NavigationData __attribute__((deprecated))
#else
# define DEPRECATED__sensors__msg__NavigationData __declspec(deprecated)
#endif

namespace sensors
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavigationData_
{
  using Type = NavigationData_<ContainerAllocator>;

  explicit NavigationData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
      this->bearing = 0.0;
      this->orientation = 0.0;
      this->isonline = false;
    }
  }

  explicit NavigationData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
      this->bearing = 0.0;
      this->orientation = 0.0;
      this->isonline = false;
    }
  }

  // field types and members
  using _distance_type =
    double;
  _distance_type distance;
  using _bearing_type =
    double;
  _bearing_type bearing;
  using _orientation_type =
    double;
  _orientation_type orientation;
  using _isonline_type =
    bool;
  _isonline_type isonline;

  // setters for named parameter idiom
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__bearing(
    const double & _arg)
  {
    this->bearing = _arg;
    return *this;
  }
  Type & set__orientation(
    const double & _arg)
  {
    this->orientation = _arg;
    return *this;
  }
  Type & set__isonline(
    const bool & _arg)
  {
    this->isonline = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sensors::msg::NavigationData_<ContainerAllocator> *;
  using ConstRawPtr =
    const sensors::msg::NavigationData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sensors::msg::NavigationData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sensors::msg::NavigationData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sensors::msg::NavigationData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sensors::msg::NavigationData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sensors::msg::NavigationData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sensors::msg::NavigationData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sensors::msg::NavigationData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sensors::msg::NavigationData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sensors__msg__NavigationData
    std::shared_ptr<sensors::msg::NavigationData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sensors__msg__NavigationData
    std::shared_ptr<sensors::msg::NavigationData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigationData_ & other) const
  {
    if (this->distance != other.distance) {
      return false;
    }
    if (this->bearing != other.bearing) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    if (this->isonline != other.isonline) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigationData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigationData_

// alias to use template instance with default allocator
using NavigationData =
  sensors::msg::NavigationData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sensors

#endif  // SENSORS__MSG__DETAIL__NAVIGATION_DATA__STRUCT_HPP_
