// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/BBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__B_BOX__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__B_BOX__BUILDER_HPP_

#include "custom_msgs/msg/detail/b_box__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_BBox_box_id
{
public:
  explicit Init_BBox_box_id(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::BBox box_id(::custom_msgs::msg::BBox::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_timestamp_ms
{
public:
  explicit Init_BBox_timestamp_ms(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_box_id timestamp_ms(::custom_msgs::msg::BBox::_timestamp_ms_type arg)
  {
    msg_.timestamp_ms = std::move(arg);
    return Init_BBox_box_id(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_px_to_ms
{
public:
  explicit Init_BBox_px_to_ms(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_timestamp_ms px_to_ms(::custom_msgs::msg::BBox::_px_to_ms_type arg)
  {
    msg_.px_to_ms = std::move(arg);
    return Init_BBox_timestamp_ms(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_px_to_mm
{
public:
  explicit Init_BBox_px_to_mm(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_px_to_ms px_to_mm(::custom_msgs::msg::BBox::_px_to_mm_type arg)
  {
    msg_.px_to_mm = std::move(arg);
    return Init_BBox_px_to_ms(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_class_label
{
public:
  explicit Init_BBox_class_label(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_px_to_mm class_label(::custom_msgs::msg::BBox::_class_label_type arg)
  {
    msg_.class_label = std::move(arg);
    return Init_BBox_px_to_mm(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_score
{
public:
  explicit Init_BBox_score(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_class_label score(::custom_msgs::msg::BBox::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_BBox_class_label(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_bottom_right_y
{
public:
  explicit Init_BBox_bottom_right_y(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_score bottom_right_y(::custom_msgs::msg::BBox::_bottom_right_y_type arg)
  {
    msg_.bottom_right_y = std::move(arg);
    return Init_BBox_score(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_bottom_right_x
{
public:
  explicit Init_BBox_bottom_right_x(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_bottom_right_y bottom_right_x(::custom_msgs::msg::BBox::_bottom_right_x_type arg)
  {
    msg_.bottom_right_x = std::move(arg);
    return Init_BBox_bottom_right_y(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_top_left_y
{
public:
  explicit Init_BBox_top_left_y(::custom_msgs::msg::BBox & msg)
  : msg_(msg)
  {}
  Init_BBox_bottom_right_x top_left_y(::custom_msgs::msg::BBox::_top_left_y_type arg)
  {
    msg_.top_left_y = std::move(arg);
    return Init_BBox_bottom_right_x(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

class Init_BBox_top_left_x
{
public:
  Init_BBox_top_left_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BBox_top_left_y top_left_x(::custom_msgs::msg::BBox::_top_left_x_type arg)
  {
    msg_.top_left_x = std::move(arg);
    return Init_BBox_top_left_y(msg_);
  }

private:
  ::custom_msgs::msg::BBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::BBox>()
{
  return custom_msgs::msg::builder::Init_BBox_top_left_x();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__B_BOX__BUILDER_HPP_
