// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msgs:msg/BBox.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/b_box__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/b_box__struct.h"
#include "custom_msgs/msg/detail/b_box__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/string__functions.h"  // box_id, class_label

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_msgs
size_t get_serialized_size_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_msgs
size_t max_serialized_size_std_msgs__msg__String(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, String)();


using _BBox__ros_msg_type = custom_msgs__msg__BBox;

static bool _BBox__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BBox__ros_msg_type * ros_message = static_cast<const _BBox__ros_msg_type *>(untyped_ros_message);
  // Field name: top_left_x
  {
    cdr << ros_message->top_left_x;
  }

  // Field name: top_left_y
  {
    cdr << ros_message->top_left_y;
  }

  // Field name: bottom_right_x
  {
    cdr << ros_message->bottom_right_x;
  }

  // Field name: bottom_right_y
  {
    cdr << ros_message->bottom_right_y;
  }

  // Field name: score
  {
    cdr << ros_message->score;
  }

  // Field name: class_label
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->class_label, cdr))
    {
      return false;
    }
  }

  // Field name: px_to_mm
  {
    cdr << ros_message->px_to_mm;
  }

  // Field name: px_to_ms
  {
    cdr << ros_message->px_to_ms;
  }

  // Field name: timestamp_ms
  {
    cdr << ros_message->timestamp_ms;
  }

  // Field name: box_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->box_id, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _BBox__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BBox__ros_msg_type * ros_message = static_cast<_BBox__ros_msg_type *>(untyped_ros_message);
  // Field name: top_left_x
  {
    cdr >> ros_message->top_left_x;
  }

  // Field name: top_left_y
  {
    cdr >> ros_message->top_left_y;
  }

  // Field name: bottom_right_x
  {
    cdr >> ros_message->bottom_right_x;
  }

  // Field name: bottom_right_y
  {
    cdr >> ros_message->bottom_right_y;
  }

  // Field name: score
  {
    cdr >> ros_message->score;
  }

  // Field name: class_label
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->class_label))
    {
      return false;
    }
  }

  // Field name: px_to_mm
  {
    cdr >> ros_message->px_to_mm;
  }

  // Field name: px_to_ms
  {
    cdr >> ros_message->px_to_ms;
  }

  // Field name: timestamp_ms
  {
    cdr >> ros_message->timestamp_ms;
  }

  // Field name: box_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->box_id))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__BBox(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BBox__ros_msg_type * ros_message = static_cast<const _BBox__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name top_left_x
  {
    size_t item_size = sizeof(ros_message->top_left_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name top_left_y
  {
    size_t item_size = sizeof(ros_message->top_left_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bottom_right_x
  {
    size_t item_size = sizeof(ros_message->bottom_right_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bottom_right_y
  {
    size_t item_size = sizeof(ros_message->bottom_right_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name score
  {
    size_t item_size = sizeof(ros_message->score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name class_label

  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->class_label), current_alignment);
  // field.name px_to_mm
  {
    size_t item_size = sizeof(ros_message->px_to_mm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name px_to_ms
  {
    size_t item_size = sizeof(ros_message->px_to_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name timestamp_ms
  {
    size_t item_size = sizeof(ros_message->timestamp_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name box_id

  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->box_id), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _BBox__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msgs__msg__BBox(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__BBox(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: top_left_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: top_left_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: bottom_right_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: bottom_right_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: score
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: class_label
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__String(
        full_bounded, current_alignment);
    }
  }
  // member: px_to_mm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: px_to_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: timestamp_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: box_id
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__String(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _BBox__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_msgs__msg__BBox(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_BBox = {
  "custom_msgs::msg",
  "BBox",
  _BBox__cdr_serialize,
  _BBox__cdr_deserialize,
  _BBox__get_serialized_size,
  _BBox__max_serialized_size
};

static rosidl_message_type_support_t _BBox__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BBox,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, BBox)() {
  return &_BBox__type_support;
}

#if defined(__cplusplus)
}
#endif
