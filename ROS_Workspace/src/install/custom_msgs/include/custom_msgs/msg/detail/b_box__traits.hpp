// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/BBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__B_BOX__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__B_BOX__TRAITS_HPP_

#include "custom_msgs/msg/detail/b_box__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'class_label'
// Member 'box_id'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::msg::BBox>()
{
  return "custom_msgs::msg::BBox";
}

template<>
inline const char * name<custom_msgs::msg::BBox>()
{
  return "custom_msgs/msg/BBox";
}

template<>
struct has_fixed_size<custom_msgs::msg::BBox>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<custom_msgs::msg::BBox>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<custom_msgs::msg::BBox>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__B_BOX__TRAITS_HPP_
