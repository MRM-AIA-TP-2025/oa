// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stereo:msg/Yolotag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__YOLOTAG__STRUCT_H_
#define STEREO__MSG__DETAIL__YOLOTAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Yolotag in the package stereo.
typedef struct stereo__msg__Yolotag
{
  bool is_found;
  double x;
  double y;
  int64_t id;
} stereo__msg__Yolotag;

// Struct for a sequence of stereo__msg__Yolotag.
typedef struct stereo__msg__Yolotag__Sequence
{
  stereo__msg__Yolotag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stereo__msg__Yolotag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STEREO__MSG__DETAIL__YOLOTAG__STRUCT_H_
