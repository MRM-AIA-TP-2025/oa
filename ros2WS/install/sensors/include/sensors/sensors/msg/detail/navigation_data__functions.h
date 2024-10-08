// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sensors:msg/NavigationData.idl
// generated code does not contain a copyright notice

#ifndef SENSORS__MSG__DETAIL__NAVIGATION_DATA__FUNCTIONS_H_
#define SENSORS__MSG__DETAIL__NAVIGATION_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sensors/msg/rosidl_generator_c__visibility_control.h"

#include "sensors/msg/detail/navigation_data__struct.h"

/// Initialize msg/NavigationData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sensors__msg__NavigationData
 * )) before or use
 * sensors__msg__NavigationData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
bool
sensors__msg__NavigationData__init(sensors__msg__NavigationData * msg);

/// Finalize msg/NavigationData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
void
sensors__msg__NavigationData__fini(sensors__msg__NavigationData * msg);

/// Create msg/NavigationData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sensors__msg__NavigationData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
sensors__msg__NavigationData *
sensors__msg__NavigationData__create();

/// Destroy msg/NavigationData message.
/**
 * It calls
 * sensors__msg__NavigationData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
void
sensors__msg__NavigationData__destroy(sensors__msg__NavigationData * msg);

/// Check for msg/NavigationData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
bool
sensors__msg__NavigationData__are_equal(const sensors__msg__NavigationData * lhs, const sensors__msg__NavigationData * rhs);

/// Copy a msg/NavigationData message.
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
ROSIDL_GENERATOR_C_PUBLIC_sensors
bool
sensors__msg__NavigationData__copy(
  const sensors__msg__NavigationData * input,
  sensors__msg__NavigationData * output);

/// Initialize array of msg/NavigationData messages.
/**
 * It allocates the memory for the number of elements and calls
 * sensors__msg__NavigationData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
bool
sensors__msg__NavigationData__Sequence__init(sensors__msg__NavigationData__Sequence * array, size_t size);

/// Finalize array of msg/NavigationData messages.
/**
 * It calls
 * sensors__msg__NavigationData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
void
sensors__msg__NavigationData__Sequence__fini(sensors__msg__NavigationData__Sequence * array);

/// Create array of msg/NavigationData messages.
/**
 * It allocates the memory for the array and calls
 * sensors__msg__NavigationData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
sensors__msg__NavigationData__Sequence *
sensors__msg__NavigationData__Sequence__create(size_t size);

/// Destroy array of msg/NavigationData messages.
/**
 * It calls
 * sensors__msg__NavigationData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
void
sensors__msg__NavigationData__Sequence__destroy(sensors__msg__NavigationData__Sequence * array);

/// Check for msg/NavigationData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensors
bool
sensors__msg__NavigationData__Sequence__are_equal(const sensors__msg__NavigationData__Sequence * lhs, const sensors__msg__NavigationData__Sequence * rhs);

/// Copy an array of msg/NavigationData messages.
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
ROSIDL_GENERATOR_C_PUBLIC_sensors
bool
sensors__msg__NavigationData__Sequence__copy(
  const sensors__msg__NavigationData__Sequence * input,
  sensors__msg__NavigationData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SENSORS__MSG__DETAIL__NAVIGATION_DATA__FUNCTIONS_H_
