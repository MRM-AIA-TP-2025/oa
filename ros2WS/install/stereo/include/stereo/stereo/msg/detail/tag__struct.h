// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stereo:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__TAG__STRUCT_H_
#define STEREO__MSG__DETAIL__TAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Tag in the package stereo.
typedef struct stereo__msg__Tag
{
  bool is_found;
  double x;
  double y;
  int64_t id;
} stereo__msg__Tag;

// Struct for a sequence of stereo__msg__Tag.
typedef struct stereo__msg__Tag__Sequence
{
  stereo__msg__Tag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stereo__msg__Tag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STEREO__MSG__DETAIL__TAG__STRUCT_H_
