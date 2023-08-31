// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from custom_msgs:msg/LEDLocations.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/led_locations__rosidl_typesupport_fastrtps_cpp.hpp"
#include "custom_msgs/msg/detail/led_locations__struct.hpp"

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
  const custom_msgs::msg::LEDLocations & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: isled1
  cdr << (ros_message.isled1 ? true : false);
  // Member: isled2
  cdr << (ros_message.isled2 ? true : false);
  // Member: led1x
  cdr << ros_message.led1x;
  // Member: led2x
  cdr << ros_message.led2x;
  // Member: led1y
  cdr << ros_message.led1y;
  // Member: led2y
  cdr << ros_message.led2y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custom_msgs::msg::LEDLocations & ros_message)
{
  // Member: isled1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.isled1 = tmp ? true : false;
  }

  // Member: isled2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.isled2 = tmp ? true : false;
  }

  // Member: led1x
  cdr >> ros_message.led1x;

  // Member: led2x
  cdr >> ros_message.led2x;

  // Member: led1y
  cdr >> ros_message.led1y;

  // Member: led2y
  cdr >> ros_message.led2y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_msgs
get_serialized_size(
  const custom_msgs::msg::LEDLocations & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: isled1
  {
    size_t item_size = sizeof(ros_message.isled1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: isled2
  {
    size_t item_size = sizeof(ros_message.isled2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: led1x
  {
    size_t item_size = sizeof(ros_message.led1x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: led2x
  {
    size_t item_size = sizeof(ros_message.led2x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: led1y
  {
    size_t item_size = sizeof(ros_message.led1y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: led2y
  {
    size_t item_size = sizeof(ros_message.led2y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_msgs
max_serialized_size_LEDLocations(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: isled1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: isled2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: led1x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: led2x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: led1y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: led2y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LEDLocations__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custom_msgs::msg::LEDLocations *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LEDLocations__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custom_msgs::msg::LEDLocations *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LEDLocations__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custom_msgs::msg::LEDLocations *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LEDLocations__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LEDLocations(full_bounded, 0);
}

static message_type_support_callbacks_t _LEDLocations__callbacks = {
  "custom_msgs::msg",
  "LEDLocations",
  _LEDLocations__cdr_serialize,
  _LEDLocations__cdr_deserialize,
  _LEDLocations__get_serialized_size,
  _LEDLocations__max_serialized_size
};

static rosidl_message_type_support_t _LEDLocations__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LEDLocations__callbacks,
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
get_message_type_support_handle<custom_msgs::msg::LEDLocations>()
{
  return &custom_msgs::msg::typesupport_fastrtps_cpp::_LEDLocations__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msgs, msg, LEDLocations)() {
  return &custom_msgs::msg::typesupport_fastrtps_cpp::_LEDLocations__handle;
}

#ifdef __cplusplus
}
#endif
