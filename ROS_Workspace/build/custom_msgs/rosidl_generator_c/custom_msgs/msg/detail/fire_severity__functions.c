// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/FireSeverity.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/fire_severity__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `severity`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_msgs__msg__FireSeverity__init(custom_msgs__msg__FireSeverity * msg)
{
  if (!msg) {
    return false;
  }
  // severity
  if (!rosidl_runtime_c__String__init(&msg->severity)) {
    custom_msgs__msg__FireSeverity__fini(msg);
    return false;
  }
  // isdetected
  // fire_x
  // fire_y
  return true;
}

void
custom_msgs__msg__FireSeverity__fini(custom_msgs__msg__FireSeverity * msg)
{
  if (!msg) {
    return;
  }
  // severity
  rosidl_runtime_c__String__fini(&msg->severity);
  // isdetected
  // fire_x
  // fire_y
}

bool
custom_msgs__msg__FireSeverity__are_equal(const custom_msgs__msg__FireSeverity * lhs, const custom_msgs__msg__FireSeverity * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // severity
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->severity), &(rhs->severity)))
  {
    return false;
  }
  // isdetected
  if (lhs->isdetected != rhs->isdetected) {
    return false;
  }
  // fire_x
  if (lhs->fire_x != rhs->fire_x) {
    return false;
  }
  // fire_y
  if (lhs->fire_y != rhs->fire_y) {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__FireSeverity__copy(
  const custom_msgs__msg__FireSeverity * input,
  custom_msgs__msg__FireSeverity * output)
{
  if (!input || !output) {
    return false;
  }
  // severity
  if (!rosidl_runtime_c__String__copy(
      &(input->severity), &(output->severity)))
  {
    return false;
  }
  // isdetected
  output->isdetected = input->isdetected;
  // fire_x
  output->fire_x = input->fire_x;
  // fire_y
  output->fire_y = input->fire_y;
  return true;
}

custom_msgs__msg__FireSeverity *
custom_msgs__msg__FireSeverity__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__FireSeverity * msg = (custom_msgs__msg__FireSeverity *)allocator.allocate(sizeof(custom_msgs__msg__FireSeverity), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__FireSeverity));
  bool success = custom_msgs__msg__FireSeverity__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__FireSeverity__destroy(custom_msgs__msg__FireSeverity * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__FireSeverity__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__FireSeverity__Sequence__init(custom_msgs__msg__FireSeverity__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__FireSeverity * data = NULL;

  if (size) {
    data = (custom_msgs__msg__FireSeverity *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__FireSeverity), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__FireSeverity__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__FireSeverity__fini(&data[i - 1]);
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
custom_msgs__msg__FireSeverity__Sequence__fini(custom_msgs__msg__FireSeverity__Sequence * array)
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
      custom_msgs__msg__FireSeverity__fini(&array->data[i]);
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

custom_msgs__msg__FireSeverity__Sequence *
custom_msgs__msg__FireSeverity__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__FireSeverity__Sequence * array = (custom_msgs__msg__FireSeverity__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__FireSeverity__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__FireSeverity__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__FireSeverity__Sequence__destroy(custom_msgs__msg__FireSeverity__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__FireSeverity__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__FireSeverity__Sequence__are_equal(const custom_msgs__msg__FireSeverity__Sequence * lhs, const custom_msgs__msg__FireSeverity__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__FireSeverity__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__FireSeverity__Sequence__copy(
  const custom_msgs__msg__FireSeverity__Sequence * input,
  custom_msgs__msg__FireSeverity__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__FireSeverity);
    custom_msgs__msg__FireSeverity * data =
      (custom_msgs__msg__FireSeverity *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__FireSeverity__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__FireSeverity__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__FireSeverity__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
