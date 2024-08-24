// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from stereo:msg/Yolotag.idl
// generated code does not contain a copyright notice

#ifndef STEREO__MSG__DETAIL__YOLOTAG__FUNCTIONS_H_
#define STEREO__MSG__DETAIL__YOLOTAG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "stereo/msg/rosidl_generator_c__visibility_control.h"

#include "stereo/msg/detail/yolotag__struct.h"

/// Initialize msg/Yolotag message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * stereo__msg__Yolotag
 * )) before or use
 * stereo__msg__Yolotag__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
bool
stereo__msg__Yolotag__init(stereo__msg__Yolotag * msg);

/// Finalize msg/Yolotag message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
void
stereo__msg__Yolotag__fini(stereo__msg__Yolotag * msg);

/// Create msg/Yolotag message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * stereo__msg__Yolotag__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
stereo__msg__Yolotag *
stereo__msg__Yolotag__create();

/// Destroy msg/Yolotag message.
/**
 * It calls
 * stereo__msg__Yolotag__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
void
stereo__msg__Yolotag__destroy(stereo__msg__Yolotag * msg);

/// Check for msg/Yolotag message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
bool
stereo__msg__Yolotag__are_equal(const stereo__msg__Yolotag * lhs, const stereo__msg__Yolotag * rhs);

/// Copy a msg/Yolotag message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
bool
stereo__msg__Yolotag__copy(
  const stereo__msg__Yolotag * input,
  stereo__msg__Yolotag * output);

/// Initialize array of msg/Yolotag messages.
/**
 * It allocates the memory for the number of elements and calls
 * stereo__msg__Yolotag__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
bool
stereo__msg__Yolotag__Sequence__init(stereo__msg__Yolotag__Sequence * array, size_t size);

/// Finalize array of msg/Yolotag messages.
/**
 * It calls
 * stereo__msg__Yolotag__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
void
stereo__msg__Yolotag__Sequence__fini(stereo__msg__Yolotag__Sequence * array);

/// Create array of msg/Yolotag messages.
/**
 * It allocates the memory for the array and calls
 * stereo__msg__Yolotag__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
stereo__msg__Yolotag__Sequence *
stereo__msg__Yolotag__Sequence__create(size_t size);

/// Destroy array of msg/Yolotag messages.
/**
 * It calls
 * stereo__msg__Yolotag__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
void
stereo__msg__Yolotag__Sequence__destroy(stereo__msg__Yolotag__Sequence * array);

/// Check for msg/Yolotag message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
bool
stereo__msg__Yolotag__Sequence__are_equal(const stereo__msg__Yolotag__Sequence * lhs, const stereo__msg__Yolotag__Sequence * rhs);

/// Copy an array of msg/Yolotag messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_stereo
bool
stereo__msg__Yolotag__Sequence__copy(
  const stereo__msg__Yolotag__Sequence * input,
  stereo__msg__Yolotag__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // STEREO__MSG__DETAIL__YOLOTAG__FUNCTIONS_H_
