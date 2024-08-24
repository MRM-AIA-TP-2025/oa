// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stereo:msg/Yolotag.idl
// generated code does not contain a copyright notice
#include "stereo/msg/detail/yolotag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
stereo__msg__Yolotag__init(stereo__msg__Yolotag * msg)
{
  if (!msg) {
    return false;
  }
  // is_found
  // x
  // y
  // id
  return true;
}

void
stereo__msg__Yolotag__fini(stereo__msg__Yolotag * msg)
{
  if (!msg) {
    return;
  }
  // is_found
  // x
  // y
  // id
}

bool
stereo__msg__Yolotag__are_equal(const stereo__msg__Yolotag * lhs, const stereo__msg__Yolotag * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_found
  if (lhs->is_found != rhs->is_found) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  return true;
}

bool
stereo__msg__Yolotag__copy(
  const stereo__msg__Yolotag * input,
  stereo__msg__Yolotag * output)
{
  if (!input || !output) {
    return false;
  }
  // is_found
  output->is_found = input->is_found;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // id
  output->id = input->id;
  return true;
}

stereo__msg__Yolotag *
stereo__msg__Yolotag__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stereo__msg__Yolotag * msg = (stereo__msg__Yolotag *)allocator.allocate(sizeof(stereo__msg__Yolotag), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stereo__msg__Yolotag));
  bool success = stereo__msg__Yolotag__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stereo__msg__Yolotag__destroy(stereo__msg__Yolotag * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stereo__msg__Yolotag__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stereo__msg__Yolotag__Sequence__init(stereo__msg__Yolotag__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stereo__msg__Yolotag * data = NULL;

  if (size) {
    data = (stereo__msg__Yolotag *)allocator.zero_allocate(size, sizeof(stereo__msg__Yolotag), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stereo__msg__Yolotag__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stereo__msg__Yolotag__fini(&data[i - 1]);
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
stereo__msg__Yolotag__Sequence__fini(stereo__msg__Yolotag__Sequence * array)
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
      stereo__msg__Yolotag__fini(&array->data[i]);
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

stereo__msg__Yolotag__Sequence *
stereo__msg__Yolotag__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stereo__msg__Yolotag__Sequence * array = (stereo__msg__Yolotag__Sequence *)allocator.allocate(sizeof(stereo__msg__Yolotag__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stereo__msg__Yolotag__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stereo__msg__Yolotag__Sequence__destroy(stereo__msg__Yolotag__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stereo__msg__Yolotag__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stereo__msg__Yolotag__Sequence__are_equal(const stereo__msg__Yolotag__Sequence * lhs, const stereo__msg__Yolotag__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stereo__msg__Yolotag__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stereo__msg__Yolotag__Sequence__copy(
  const stereo__msg__Yolotag__Sequence * input,
  stereo__msg__Yolotag__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stereo__msg__Yolotag);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stereo__msg__Yolotag * data =
      (stereo__msg__Yolotag *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stereo__msg__Yolotag__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stereo__msg__Yolotag__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stereo__msg__Yolotag__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
