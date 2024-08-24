// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensors:msg/NavigationData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__NAVIGATION_DATA__STRUCT_H_
#define SENSORS__MSG__DETAIL__NAVIGATION_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/NavigationData in the package sensors.
typedef struct sensors__msg__NavigationData
{
  double distance;
  double bearing;
  double orientation;
  bool isonline;
} sensors__msg__NavigationData;

// Struct for a sequence of sensors__msg__NavigationData.
typedef struct sensors__msg__NavigationData__Sequence
{
  sensors__msg__NavigationData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sensors__msg__NavigationData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SENSORS__MSG__DETAIL__NAVIGATION_DATA__STRUCT_H_
