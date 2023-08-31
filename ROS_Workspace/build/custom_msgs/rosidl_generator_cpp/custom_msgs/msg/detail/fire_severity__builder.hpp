// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/FireSeverity.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__BUILDER_HPP_

#include "custom_msgs/msg/detail/fire_severity__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_FireSeverity_fire_y
{
public:
  explicit Init_FireSeverity_fire_y(::custom_msgs::msg::FireSeverity & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::FireSeverity fire_y(::custom_msgs::msg::FireSeverity::_fire_y_type arg)
  {
    msg_.fire_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::FireSeverity msg_;
};

class Init_FireSeverity_fire_x
{
public:
  explicit Init_FireSeverity_fire_x(::custom_msgs::msg::FireSeverity & msg)
  : msg_(msg)
  {}
  Init_FireSeverity_fire_y fire_x(::custom_msgs::msg::FireSeverity::_fire_x_type arg)
  {
    msg_.fire_x = std::move(arg);
    return Init_FireSeverity_fire_y(msg_);
  }

private:
  ::custom_msgs::msg::FireSeverity msg_;
};

class Init_FireSeverity_isdetected
{
public:
  explicit Init_FireSeverity_isdetected(::custom_msgs::msg::FireSeverity & msg)
  : msg_(msg)
  {}
  Init_FireSeverity_fire_x isdetected(::custom_msgs::msg::FireSeverity::_isdetected_type arg)
  {
    msg_.isdetected = std::move(arg);
    return Init_FireSeverity_fire_x(msg_);
  }

private:
  ::custom_msgs::msg::FireSeverity msg_;
};

class Init_FireSeverity_severity
{
public:
  Init_FireSeverity_severity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FireSeverity_isdetected severity(::custom_msgs::msg::FireSeverity::_severity_type arg)
  {
    msg_.severity = std::move(arg);
    return Init_FireSeverity_isdetected(msg_);
  }

private:
  ::custom_msgs::msg::FireSeverity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::FireSeverity>()
{
  return custom_msgs::msg::builder::Init_FireSeverity_severity();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__BUILDER_HPP_
