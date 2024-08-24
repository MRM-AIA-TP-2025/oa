// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sensors:msg/ImuData.idl
// generated code does not contain a copyright notice
#include "sensors/msg/detail/imu_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `acceleration`
// Member `orientation`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
sensors__msg__ImuData__init(sensors__msg__ImuData * msg)
{
  if (!msg) {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->acceleration)) {
    sensors__msg__ImuData__fini(msg);
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Vector3__init(&msg->orientation)) {
    sensors__msg__ImuData__fini(msg);
    return false;
  }
  return true;
}

void
sensors__msg__ImuData__fini(sensors__msg__ImuData * msg)
{
  if (!msg) {
    return;
  }
  // acceleration
  geometry_msgs__msg__Vector3__fini(&msg->acceleration);
  // orientation
  geometry_msgs__msg__Vector3__fini(&msg->orientation);
}

bool
sensors__msg__ImuData__are_equal(const sensors__msg__ImuData * lhs, const sensors__msg__ImuData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->acceleration), &(rhs->acceleration)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->orientation), &(rhs->orientation)))
  {
    return false;
  }
  return true;
}

bool
sensors__msg__ImuData__copy(
  const sensors__msg__ImuData * input,
  sensors__msg__ImuData * output)
{
  if (!input || !output) {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->acceleration), &(output->acceleration)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->orientation), &(output->orientation)))
  {
    return false;
  }
  return true;
}

sensors__msg__ImuData *
sensors__msg__ImuData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sensors__msg__ImuData * msg = (sensors__msg__ImuData *)allocator.allocate(sizeof(sensors__msg__ImuData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sensors__msg__ImuData));
  bool success = sensors__msg__ImuData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sensors__msg__ImuData__destroy(sensors__msg__ImuData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sensors__msg__ImuData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sensors__msg__ImuData__Sequence__init(sensors__msg__ImuData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sensors__msg__ImuData * data = NULL;

  if (size) {
    data = (sensors__msg__ImuData *)allocator.zero_allocate(size, sizeof(sensors__msg__ImuData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sensors__msg__ImuData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sensors__msg__ImuData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sensors__msg__ImuData__Sequence__fini(sensors__msg__ImuData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sensors__msg__ImuData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sensors__msg__ImuData__Sequence *
sensors__msg__ImuData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sensors__msg__ImuData__Sequence * array = (sensors__msg__ImuData__Sequence *)allocator.allocate(sizeof(sensors__msg__ImuData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sensors__msg__ImuData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sensors__msg__ImuData__Sequence__destroy(sensors__msg__ImuData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sensors__msg__ImuData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sensors__msg__ImuData__Sequence__are_equal(const sensors__msg__ImuData__Sequence * lhs, const sensors__msg__ImuData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sensors__msg__ImuData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sensors__msg__ImuData__Sequence__copy(
  const sensors__msg__ImuData__Sequence * input,
  sensors__msg__ImuData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sensors__msg__ImuData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sensors__msg__ImuData * data =
      (sensors__msg__ImuData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sensors__msg__ImuData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sensors__msg__ImuData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sensors__msg__ImuData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
