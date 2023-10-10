// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/FireSeverity.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__FireSeverity __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__FireSeverity __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FireSeverity_
{
  using Type = FireSeverity_<ContainerAllocator>;

  explicit FireSeverity_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->severity = "";
      this->isdetected = false;
      this->fire_x = 0.0f;
      this->fire_y = 0.0f;
    }
  }

  explicit FireSeverity_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : severity(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->severity = "";
      this->isdetected = false;
      this->fire_x = 0.0f;
      this->fire_y = 0.0f;
    }
  }

  // field types and members
  using _severity_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _severity_type severity;
  using _isdetected_type =
    bool;
  _isdetected_type isdetected;
  using _fire_x_type =
    float;
  _fire_x_type fire_x;
  using _fire_y_type =
    float;
  _fire_y_type fire_y;

  // setters for named parameter idiom
  Type & set__severity(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->severity = _arg;
    return *this;
  }
  Type & set__isdetected(
    const bool & _arg)
  {
    this->isdetected = _arg;
    return *this;
  }
  Type & set__fire_x(
    const float & _arg)
  {
    this->fire_x = _arg;
    return *this;
  }
  Type & set__fire_y(
    const float & _arg)
  {
    this->fire_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::FireSeverity_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::FireSeverity_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::FireSeverity_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::FireSeverity_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__FireSeverity
    std::shared_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__FireSeverity
    std::shared_ptr<custom_msgs::msg::FireSeverity_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FireSeverity_ & other) const
  {
    if (this->severity != other.severity) {
      return false;
    }
    if (this->isdetected != other.isdetected) {
      return false;
    }
    if (this->fire_x != other.fire_x) {
      return false;
    }
    if (this->fire_y != other.fire_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const FireSeverity_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FireSeverity_

// alias to use template instance with default allocator
using FireSeverity =
  custom_msgs::msg::FireSeverity_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__STRUCT_HPP_
