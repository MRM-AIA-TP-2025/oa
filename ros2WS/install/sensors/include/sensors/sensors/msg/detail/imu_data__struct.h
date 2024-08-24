// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensors:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__IMU_DATA__STRUCT_H_
#define SENSORS__MSG__DETAIL__IMU_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'acceleration'
// Member 'orientation'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/ImuData in the package sensors.
typedef struct sensors__msg__ImuData
{
  geometry_msgs__msg__Vector3 acceleration;
  geometry_msgs__msg__Vector3 orientation;
} sensors__msg__ImuData;

// Struct for a sequence of sensors__msg__ImuData.
typedef struct sensors__msg__ImuData__Sequence
{
  sensors__msg__ImuData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sensors__msg__ImuData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SENSORS__MSG__DETAIL__IMU_DATA__STRUCT_H_
