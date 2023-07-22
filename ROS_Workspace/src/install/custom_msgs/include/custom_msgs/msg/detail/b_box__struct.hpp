// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/BBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__B_BOX__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__B_BOX__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'class_label'
// Member 'box_id'
#include "std_msgs/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__BBox __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__BBox __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BBox_
{
  using Type = BBox_<ContainerAllocator>;

  explicit BBox_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_label(_init),
    box_id(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->top_left_x = 0ul;
      this->top_left_y = 0ul;
      this->bottom_right_x = 0ul;
      this->bottom_right_y = 0ul;
      this->score = 0.0f;
      this->px_to_mm = 0.0f;
      this->px_to_ms = 0.0f;
      this->timestamp_ms = 0ull;
    }
  }

  explicit BBox_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_label(_alloc, _init),
    box_id(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->top_left_x = 0ul;
      this->top_left_y = 0ul;
      this->bottom_right_x = 0ul;
      this->bottom_right_y = 0ul;
      this->score = 0.0f;
      this->px_to_mm = 0.0f;
      this->px_to_ms = 0.0f;
      this->timestamp_ms = 0ull;
    }
  }

  // field types and members
  using _top_left_x_type =
    uint32_t;
  _top_left_x_type top_left_x;
  using _top_left_y_type =
    uint32_t;
  _top_left_y_type top_left_y;
  using _bottom_right_x_type =
    uint32_t;
  _bottom_right_x_type bottom_right_x;
  using _bottom_right_y_type =
    uint32_t;
  _bottom_right_y_type bottom_right_y;
  using _score_type =
    float;
  _score_type score;
  using _class_label_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _class_label_type class_label;
  using _px_to_mm_type =
    float;
  _px_to_mm_type px_to_mm;
  using _px_to_ms_type =
    float;
  _px_to_ms_type px_to_ms;
  using _timestamp_ms_type =
    uint64_t;
  _timestamp_ms_type timestamp_ms;
  using _box_id_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _box_id_type box_id;

  // setters for named parameter idiom
  Type & set__top_left_x(
    const uint32_t & _arg)
  {
    this->top_left_x = _arg;
    return *this;
  }
  Type & set__top_left_y(
    const uint32_t & _arg)
  {
    this->top_left_y = _arg;
    return *this;
  }
  Type & set__bottom_right_x(
    const uint32_t & _arg)
  {
    this->bottom_right_x = _arg;
    return *this;
  }
  Type & set__bottom_right_y(
    const uint32_t & _arg)
  {
    this->bottom_right_y = _arg;
    return *this;
  }
  Type & set__score(
    const float & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__class_label(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->class_label = _arg;
    return *this;
  }
  Type & set__px_to_mm(
    const float & _arg)
  {
    this->px_to_mm = _arg;
    return *this;
  }
  Type & set__px_to_ms(
    const float & _arg)
  {
    this->px_to_ms = _arg;
    return *this;
  }
  Type & set__timestamp_ms(
    const uint64_t & _arg)
  {
    this->timestamp_ms = _arg;
    return *this;
  }
  Type & set__box_id(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->box_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::BBox_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::BBox_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::BBox_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::BBox_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::BBox_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::BBox_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::BBox_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::BBox_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::BBox_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::BBox_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__BBox
    std::shared_ptr<custom_msgs::msg::BBox_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__BBox
    std::shared_ptr<custom_msgs::msg::BBox_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BBox_ & other) const
  {
    if (this->top_left_x != other.top_left_x) {
      return false;
    }
    if (this->top_left_y != other.top_left_y) {
      return false;
    }
    if (this->bottom_right_x != other.bottom_right_x) {
      return false;
    }
    if (this->bottom_right_y != other.bottom_right_y) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->class_label != other.class_label) {
      return false;
    }
    if (this->px_to_mm != other.px_to_mm) {
      return false;
    }
    if (this->px_to_ms != other.px_to_ms) {
      return false;
    }
    if (this->timestamp_ms != other.timestamp_ms) {
      return false;
    }
    if (this->box_id != other.box_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const BBox_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BBox_

// alias to use template instance with default allocator
using BBox =
  custom_msgs::msg::BBox_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__B_BOX__STRUCT_HPP_
