// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sensors:msg/Pclo.idl
// generated code does not contain a copyright notice
#include "sensors/msg/detail/pclo__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sensors__msg__Pclo__init(sensors__msg__Pclo * msg)
{
  if (!msg) {
    return false;
  }
  // front
  // left
  // right
  return true;
}

void
sensors__msg__Pclo__fini(sensors__msg__Pclo * msg)
{
  if (!msg) {
    return;
  }
  // front
  // left
  // right
}

bool
sensors__msg__Pclo__are_equal(const sensors__msg__Pclo * lhs, const sensors__msg__Pclo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // front
  if (lhs->front != rhs->front) {
    return false;
  }
  // left
  if (lhs->left != rhs->left) {
    return false;
  }
  // right
  if (lhs->right != rhs->right) {
    return false;
  }
  return true;
}

bool
sensors__msg__Pclo__copy(
  const sensors__msg__Pclo * input,
  sensors__msg__Pclo * output)
{
  if (!input || !output) {
    return false;
  }
  // front
  output->front = input->front;
  // left
  output->left = input->left;
  // right
  output->right = input->right;
  return true;
}

sensors__msg__Pclo *
sensors__msg__Pclo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sensors__msg__Pclo * msg = (sensors__msg__Pclo *)allocator.allocate(sizeof(sensors__msg__Pclo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sensors__msg__Pclo));
  bool success = sensors__msg__Pclo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sensors__msg__Pclo__destroy(sensors__msg__Pclo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sensors__msg__Pclo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sensors__msg__Pclo__Sequence__init(sensors__msg__Pclo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sensors__msg__Pclo * data = NULL;

  if (size) {
    data = (sensors__msg__Pclo *)allocator.zero_allocate(size, sizeof(sensors__msg__Pclo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sensors__msg__Pclo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sensors__msg__Pclo__fini(&data[i - 1]);
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
sensors__msg__Pclo__Sequence__fini(sensors__msg__Pclo__Sequence * array)
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
      sensors__msg__Pclo__fini(&array->data[i]);
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

sensors__msg__Pclo__Sequence *
sensors__msg__Pclo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sensors__msg__Pclo__Sequence * array = (sensors__msg__Pclo__Sequence *)allocator.allocate(sizeof(sensors__msg__Pclo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sensors__msg__Pclo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sensors__msg__Pclo__Sequence__destroy(sensors__msg__Pclo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sensors__msg__Pclo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sensors__msg__Pclo__Sequence__are_equal(const sensors__msg__Pclo__Sequence * lhs, const sensors__msg__Pclo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sensors__msg__Pclo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sensors__msg__Pclo__Sequence__copy(
  const sensors__msg__Pclo__Sequence * input,
  sensors__msg__Pclo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sensors__msg__Pclo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sensors__msg__Pclo * data =
      (sensors__msg__Pclo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sensors__msg__Pclo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sensors__msg__Pclo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sensors__msg__Pclo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
