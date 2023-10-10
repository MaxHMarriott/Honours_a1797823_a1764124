// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from custom_msgs:msg/FireSeverity.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/fire_severity__rosidl_typesupport_fastrtps_cpp.hpp"
#include "custom_msgs/msg/detail/fire_severity__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace custom_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_msgs
cdr_serialize(
  const custom_msgs::msg::FireSeverity & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: severity
  cdr << ros_message.severity;
  // Member: isdetected
  cdr << (ros_message.isdetected ? true : false);
  // Member: fire_x
  cdr << ros_message.fire_x;
  // Member: fire_y
  cdr << ros_message.fire_y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custom_msgs::msg::FireSeverity & ros_message)
{
  // Member: severity
  cdr >> ros_message.severity;

  // Member: isdetected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.isdetected = tmp ? true : false;
  }

  // Member: fire_x
  cdr >> ros_message.fire_x;

  // Member: fire_y
  cdr >> ros_message.fire_y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_msgs
get_serialized_size(
  const custom_msgs::msg::FireSeverity & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: severity
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.severity.size() + 1);
  // Member: isdetected
  {
    size_t item_size = sizeof(ros_message.isdetected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fire_x
  {
    size_t item_size = sizeof(ros_message.fire_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fire_y
  {
    size_t item_size = sizeof(ros_message.fire_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_msgs
max_serialized_size_FireSeverity(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: severity
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: isdetected
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: fire_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: fire_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _FireSeverity__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custom_msgs::msg::FireSeverity *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FireSeverity__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custom_msgs::msg::FireSeverity *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FireSeverity__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custom_msgs::msg::FireSeverity *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FireSeverity__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_FireSeverity(full_bounded, 0);
}

static message_type_support_callbacks_t _FireSeverity__callbacks = {
  "custom_msgs::msg",
  "FireSeverity",
  _FireSeverity__cdr_serialize,
  _FireSeverity__cdr_deserialize,
  _FireSeverity__get_serialized_size,
  _FireSeverity__max_serialized_size
};

static rosidl_message_type_support_t _FireSeverity__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FireSeverity__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace custom_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msgs::msg::FireSeverity>()
{
  return &custom_msgs::msg::typesupport_fastrtps_cpp::_FireSeverity__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msgs, msg, FireSeverity)() {
  return &custom_msgs::msg::typesupport_fastrtps_cpp::_FireSeverity__handle;
}

#ifdef __cplusplus
}
#endif
