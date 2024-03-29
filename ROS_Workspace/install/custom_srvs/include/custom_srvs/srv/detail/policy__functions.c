// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_srvs:srv/Policy.idl
// generated code does not contain a copyright notice
#include "custom_srvs/srv/detail/policy__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `location`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
custom_srvs__srv__Policy_Request__init(custom_srvs__srv__Policy_Request * msg)
{
  if (!msg) {
    return false;
  }
  // location
  if (!geometry_msgs__msg__Point__init(&msg->location)) {
    custom_srvs__srv__Policy_Request__fini(msg);
    return false;
  }
  // eta
  return true;
}

void
custom_srvs__srv__Policy_Request__fini(custom_srvs__srv__Policy_Request * msg)
{
  if (!msg) {
    return;
  }
  // location
  geometry_msgs__msg__Point__fini(&msg->location);
  // eta
}

bool
custom_srvs__srv__Policy_Request__are_equal(const custom_srvs__srv__Policy_Request * lhs, const custom_srvs__srv__Policy_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // location
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->location), &(rhs->location)))
  {
    return false;
  }
  // eta
  if (lhs->eta != rhs->eta) {
    return false;
  }
  return true;
}

bool
custom_srvs__srv__Policy_Request__copy(
  const custom_srvs__srv__Policy_Request * input,
  custom_srvs__srv__Policy_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // location
  if (!geometry_msgs__msg__Point__copy(
      &(input->location), &(output->location)))
  {
    return false;
  }
  // eta
  output->eta = input->eta;
  return true;
}

custom_srvs__srv__Policy_Request *
custom_srvs__srv__Policy_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_srvs__srv__Policy_Request * msg = (custom_srvs__srv__Policy_Request *)allocator.allocate(sizeof(custom_srvs__srv__Policy_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_srvs__srv__Policy_Request));
  bool success = custom_srvs__srv__Policy_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_srvs__srv__Policy_Request__destroy(custom_srvs__srv__Policy_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_srvs__srv__Policy_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_srvs__srv__Policy_Request__Sequence__init(custom_srvs__srv__Policy_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_srvs__srv__Policy_Request * data = NULL;

  if (size) {
    data = (custom_srvs__srv__Policy_Request *)allocator.zero_allocate(size, sizeof(custom_srvs__srv__Policy_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_srvs__srv__Policy_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_srvs__srv__Policy_Request__fini(&data[i - 1]);
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
custom_srvs__srv__Policy_Request__Sequence__fini(custom_srvs__srv__Policy_Request__Sequence * array)
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
      custom_srvs__srv__Policy_Request__fini(&array->data[i]);
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

custom_srvs__srv__Policy_Request__Sequence *
custom_srvs__srv__Policy_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_srvs__srv__Policy_Request__Sequence * array = (custom_srvs__srv__Policy_Request__Sequence *)allocator.allocate(sizeof(custom_srvs__srv__Policy_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_srvs__srv__Policy_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_srvs__srv__Policy_Request__Sequence__destroy(custom_srvs__srv__Policy_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_srvs__srv__Policy_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_srvs__srv__Policy_Request__Sequence__are_equal(const custom_srvs__srv__Policy_Request__Sequence * lhs, const custom_srvs__srv__Policy_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_srvs__srv__Policy_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_srvs__srv__Policy_Request__Sequence__copy(
  const custom_srvs__srv__Policy_Request__Sequence * input,
  custom_srvs__srv__Policy_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_srvs__srv__Policy_Request);
    custom_srvs__srv__Policy_Request * data =
      (custom_srvs__srv__Policy_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_srvs__srv__Policy_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_srvs__srv__Policy_Request__fini(&data[i]);
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
    if (!custom_srvs__srv__Policy_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `ack`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_srvs__srv__Policy_Response__init(custom_srvs__srv__Policy_Response * msg)
{
  if (!msg) {
    return false;
  }
  // ack
  if (!rosidl_runtime_c__String__init(&msg->ack)) {
    custom_srvs__srv__Policy_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_srvs__srv__Policy_Response__fini(custom_srvs__srv__Policy_Response * msg)
{
  if (!msg) {
    return;
  }
  // ack
  rosidl_runtime_c__String__fini(&msg->ack);
}

bool
custom_srvs__srv__Policy_Response__are_equal(const custom_srvs__srv__Policy_Response * lhs, const custom_srvs__srv__Policy_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ack
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->ack), &(rhs->ack)))
  {
    return false;
  }
  return true;
}

bool
custom_srvs__srv__Policy_Response__copy(
  const custom_srvs__srv__Policy_Response * input,
  custom_srvs__srv__Policy_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // ack
  if (!rosidl_runtime_c__String__copy(
      &(input->ack), &(output->ack)))
  {
    return false;
  }
  return true;
}

custom_srvs__srv__Policy_Response *
custom_srvs__srv__Policy_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_srvs__srv__Policy_Response * msg = (custom_srvs__srv__Policy_Response *)allocator.allocate(sizeof(custom_srvs__srv__Policy_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_srvs__srv__Policy_Response));
  bool success = custom_srvs__srv__Policy_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_srvs__srv__Policy_Response__destroy(custom_srvs__srv__Policy_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_srvs__srv__Policy_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_srvs__srv__Policy_Response__Sequence__init(custom_srvs__srv__Policy_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_srvs__srv__Policy_Response * data = NULL;

  if (size) {
    data = (custom_srvs__srv__Policy_Response *)allocator.zero_allocate(size, sizeof(custom_srvs__srv__Policy_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_srvs__srv__Policy_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_srvs__srv__Policy_Response__fini(&data[i - 1]);
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
custom_srvs__srv__Policy_Response__Sequence__fini(custom_srvs__srv__Policy_Response__Sequence * array)
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
      custom_srvs__srv__Policy_Response__fini(&array->data[i]);
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

custom_srvs__srv__Policy_Response__Sequence *
custom_srvs__srv__Policy_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_srvs__srv__Policy_Response__Sequence * array = (custom_srvs__srv__Policy_Response__Sequence *)allocator.allocate(sizeof(custom_srvs__srv__Policy_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_srvs__srv__Policy_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_srvs__srv__Policy_Response__Sequence__destroy(custom_srvs__srv__Policy_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_srvs__srv__Policy_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_srvs__srv__Policy_Response__Sequence__are_equal(const custom_srvs__srv__Policy_Response__Sequence * lhs, const custom_srvs__srv__Policy_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_srvs__srv__Policy_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_srvs__srv__Policy_Response__Sequence__copy(
  const custom_srvs__srv__Policy_Response__Sequence * input,
  custom_srvs__srv__Policy_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_srvs__srv__Policy_Response);
    custom_srvs__srv__Policy_Response * data =
      (custom_srvs__srv__Policy_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_srvs__srv__Policy_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_srvs__srv__Policy_Response__fini(&data[i]);
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
    if (!custom_srvs__srv__Policy_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
