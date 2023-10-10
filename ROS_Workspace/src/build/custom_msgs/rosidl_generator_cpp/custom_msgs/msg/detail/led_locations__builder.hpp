// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/LEDLocations.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__LED_LOCATIONS__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__LED_LOCATIONS__BUILDER_HPP_

#include "custom_msgs/msg/detail/led_locations__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_LEDLocations_led2
{
public:
  explicit Init_LEDLocations_led2(::custom_msgs::msg::LEDLocations & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::LEDLocations led2(::custom_msgs::msg::LEDLocations::_led2_type arg)
  {
    msg_.led2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::LEDLocations msg_;
};

class Init_LEDLocations_led1
{
public:
  explicit Init_LEDLocations_led1(::custom_msgs::msg::LEDLocations & msg)
  : msg_(msg)
  {}
  Init_LEDLocations_led2 led1(::custom_msgs::msg::LEDLocations::_led1_type arg)
  {
    msg_.led1 = std::move(arg);
    return Init_LEDLocations_led2(msg_);
  }

private:
  ::custom_msgs::msg::LEDLocations msg_;
};

class Init_LEDLocations_isled2
{
public:
  explicit Init_LEDLocations_isled2(::custom_msgs::msg::LEDLocations & msg)
  : msg_(msg)
  {}
  Init_LEDLocations_led1 isled2(::custom_msgs::msg::LEDLocations::_isled2_type arg)
  {
    msg_.isled2 = std::move(arg);
    return Init_LEDLocations_led1(msg_);
  }

private:
  ::custom_msgs::msg::LEDLocations msg_;
};

class Init_LEDLocations_isled1
{
public:
  Init_LEDLocations_isled1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LEDLocations_isled2 isled1(::custom_msgs::msg::LEDLocations::_isled1_type arg)
  {
    msg_.isled1 = std::move(arg);
    return Init_LEDLocations_isled2(msg_);
  }

private:
  ::custom_msgs::msg::LEDLocations msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::LEDLocations>()
{
  return custom_msgs::msg::builder::Init_LEDLocations_isled1();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__LED_LOCATIONS__BUILDER_HPP_
