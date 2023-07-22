// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/BBox.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/b_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_label`
// Member `box_id`
#include "std_msgs/msg/detail/string__functions.h"

bool
custom_msgs__msg__BBox__init(custom_msgs__msg__BBox * msg)
{
  if (!msg) {
    return false;
  }
  // top_left_x
  // top_left_y
  // bottom_right_x
  // bottom_right_y
  // score
  // class_label
  if (!std_msgs__msg__String__init(&msg->class_label)) {
    custom_msgs__msg__BBox__fini(msg);
    return false;
  }
  // px_to_mm
  // px_to_ms
  // timestamp_ms
  // box_id
  if (!std_msgs__msg__String__init(&msg->box_id)) {
    custom_msgs__msg__BBox__fini(msg);
    return false;
  }
  return true;
}

void
custom_msgs__msg__BBox__fini(custom_msgs__msg__BBox * msg)
{
  if (!msg) {
    return;
  }
  // top_left_x
  // top_left_y
  // bottom_right_x
  // bottom_right_y
  // score
  // class_label
  std_msgs__msg__String__fini(&msg->class_label);
  // px_to_mm
  // px_to_ms
  // timestamp_ms
  // box_id
  std_msgs__msg__String__fini(&msg->box_id);
}

bool
custom_msgs__msg__BBox__are_equal(const custom_msgs__msg__BBox * lhs, const custom_msgs__msg__BBox * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // top_left_x
  if (lhs->top_left_x != rhs->top_left_x) {
    return false;
  }
  // top_left_y
  if (lhs->top_left_y != rhs->top_left_y) {
    return false;
  }
  // bottom_right_x
  if (lhs->bottom_right_x != rhs->bottom_right_x) {
    return false;
  }
  // bottom_right_y
  if (lhs->bottom_right_y != rhs->bottom_right_y) {
    return false;
  }
  // score
  if (lhs->score != rhs->score) {
    return false;
  }
  // class_label
  if (!std_msgs__msg__String__are_equal(
      &(lhs->class_label), &(rhs->class_label)))
  {
    return false;
  }
  // px_to_mm
  if (lhs->px_to_mm != rhs->px_to_mm) {
    return false;
  }
  // px_to_ms
  if (lhs->px_to_ms != rhs->px_to_ms) {
    return false;
  }
  // timestamp_ms
  if (lhs->timestamp_ms != rhs->timestamp_ms) {
    return false;
  }
  // box_id
  if (!std_msgs__msg__String__are_equal(
      &(lhs->box_id), &(rhs->box_id)))
  {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__BBox__copy(
  const custom_msgs__msg__BBox * input,
  custom_msgs__msg__BBox * output)
{
  if (!input || !output) {
    return false;
  }
  // top_left_x
  output->top_left_x = input->top_left_x;
  // top_left_y
  output->top_left_y = input->top_left_y;
  // bottom_right_x
  output->bottom_right_x = input->bottom_right_x;
  // bottom_right_y
  output->bottom_right_y = input->bottom_right_y;
  // score
  output->score = input->score;
  // class_label
  if (!std_msgs__msg__String__copy(
      &(input->class_label), &(output->class_label)))
  {
    return false;
  }
  // px_to_mm
  output->px_to_mm = input->px_to_mm;
  // px_to_ms
  output->px_to_ms = input->px_to_ms;
  // timestamp_ms
  output->timestamp_ms = input->timestamp_ms;
  // box_id
  if (!std_msgs__msg__String__copy(
      &(input->box_id), &(output->box_id)))
  {
    return false;
  }
  return true;
}

custom_msgs__msg__BBox *
custom_msgs__msg__BBox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__BBox * msg = (custom_msgs__msg__BBox *)allocator.allocate(sizeof(custom_msgs__msg__BBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__BBox));
  bool success = custom_msgs__msg__BBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__BBox__destroy(custom_msgs__msg__BBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__BBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__BBox__Sequence__init(custom_msgs__msg__BBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__BBox * data = NULL;

  if (size) {
    data = (custom_msgs__msg__BBox *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__BBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__BBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__BBox__fini(&data[i - 1]);
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
custom_msgs__msg__BBox__Sequence__fini(custom_msgs__msg__BBox__Sequence * array)
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
      custom_msgs__msg__BBox__fini(&array->data[i]);
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

custom_msgs__msg__BBox__Sequence *
custom_msgs__msg__BBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__BBox__Sequence * array = (custom_msgs__msg__BBox__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__BBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__BBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__BBox__Sequence__destroy(custom_msgs__msg__BBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__BBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__BBox__Sequence__are_equal(const custom_msgs__msg__BBox__Sequence * lhs, const custom_msgs__msg__BBox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__BBox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__BBox__Sequence__copy(
  const custom_msgs__msg__BBox__Sequence * input,
  custom_msgs__msg__BBox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__BBox);
    custom_msgs__msg__BBox * data =
      (custom_msgs__msg__BBox *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__BBox__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__BBox__fini(&data[i]);
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
    if (!custom_msgs__msg__BBox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
