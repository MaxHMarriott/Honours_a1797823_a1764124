// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/LEDLocations.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/led_locations__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_msgs__msg__LEDLocations__init(custom_msgs__msg__LEDLocations * msg)
{
  if (!msg) {
    return false;
  }
  // isled1
  // isled2
  // led1
  // led2
  return true;
}

void
custom_msgs__msg__LEDLocations__fini(custom_msgs__msg__LEDLocations * msg)
{
  if (!msg) {
    return;
  }
  // isled1
  // isled2
  // led1
  // led2
}

bool
custom_msgs__msg__LEDLocations__are_equal(const custom_msgs__msg__LEDLocations * lhs, const custom_msgs__msg__LEDLocations * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // isled1
  if (lhs->isled1 != rhs->isled1) {
    return false;
  }
  // isled2
  if (lhs->isled2 != rhs->isled2) {
    return false;
  }
  // led1
  if (lhs->led1 != rhs->led1) {
    return false;
  }
  // led2
  if (lhs->led2 != rhs->led2) {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__LEDLocations__copy(
  const custom_msgs__msg__LEDLocations * input,
  custom_msgs__msg__LEDLocations * output)
{
  if (!input || !output) {
    return false;
  }
  // isled1
  output->isled1 = input->isled1;
  // isled2
  output->isled2 = input->isled2;
  // led1
  output->led1 = input->led1;
  // led2
  output->led2 = input->led2;
  return true;
}

custom_msgs__msg__LEDLocations *
custom_msgs__msg__LEDLocations__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__LEDLocations * msg = (custom_msgs__msg__LEDLocations *)allocator.allocate(sizeof(custom_msgs__msg__LEDLocations), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__LEDLocations));
  bool success = custom_msgs__msg__LEDLocations__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__LEDLocations__destroy(custom_msgs__msg__LEDLocations * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__LEDLocations__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__LEDLocations__Sequence__init(custom_msgs__msg__LEDLocations__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__LEDLocations * data = NULL;

  if (size) {
    data = (custom_msgs__msg__LEDLocations *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__LEDLocations), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__LEDLocations__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__LEDLocations__fini(&data[i - 1]);
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
custom_msgs__msg__LEDLocations__Sequence__fini(custom_msgs__msg__LEDLocations__Sequence * array)
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
      custom_msgs__msg__LEDLocations__fini(&array->data[i]);
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

custom_msgs__msg__LEDLocations__Sequence *
custom_msgs__msg__LEDLocations__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__LEDLocations__Sequence * array = (custom_msgs__msg__LEDLocations__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__LEDLocations__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__LEDLocations__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__LEDLocations__Sequence__destroy(custom_msgs__msg__LEDLocations__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__LEDLocations__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__LEDLocations__Sequence__are_equal(const custom_msgs__msg__LEDLocations__Sequence * lhs, const custom_msgs__msg__LEDLocations__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__LEDLocations__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__LEDLocations__Sequence__copy(
  const custom_msgs__msg__LEDLocations__Sequence * input,
  custom_msgs__msg__LEDLocations__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__LEDLocations);
    custom_msgs__msg__LEDLocations * data =
      (custom_msgs__msg__LEDLocations *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__LEDLocations__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__LEDLocations__fini(&data[i]);
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
    if (!custom_msgs__msg__LEDLocations__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
