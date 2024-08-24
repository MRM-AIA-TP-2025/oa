// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensors:msg/Pclo.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__PCLO__STRUCT_H_
#define SENSORS__MSG__DETAIL__PCLO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Pclo in the package sensors.
typedef struct sensors__msg__Pclo
{
  bool front;
  bool left;
  bool right;
} sensors__msg__Pclo;

// Struct for a sequence of sensors__msg__Pclo.
typedef struct sensors__msg__Pclo__Sequence
{
  sensors__msg__Pclo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sensors__msg__Pclo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SENSORS__MSG__DETAIL__PCLO__STRUCT_H_
