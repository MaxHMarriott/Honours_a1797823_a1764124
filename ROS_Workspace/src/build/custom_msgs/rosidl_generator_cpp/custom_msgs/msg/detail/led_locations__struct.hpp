// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/LEDLocations.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__LED_LOCATIONS__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__LED_LOCATIONS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__LEDLocations __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__LEDLocations __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LEDLocations_
{
  using Type = LEDLocations_<ContainerAllocator>;

  explicit LEDLocations_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->isled1 = false;
      this->isled2 = false;
      this->led1 = 0;
      this->led2 = 0;
    }
  }

  explicit LEDLocations_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->isled1 = false;
      this->isled2 = false;
      this->led1 = 0;
      this->led2 = 0;
    }
  }

  // field types and members
  using _isled1_type =
    bool;
  _isled1_type isled1;
  using _isled2_type =
    bool;
  _isled2_type isled2;
  using _led1_type =
    int16_t;
  _led1_type led1;
  using _led2_type =
    int16_t;
  _led2_type led2;

  // setters for named parameter idiom
  Type & set__isled1(
    const bool & _arg)
  {
    this->isled1 = _arg;
    return *this;
  }
  Type & set__isled2(
    const bool & _arg)
  {
    this->isled2 = _arg;
    return *this;
  }
  Type & set__led1(
    const int16_t & _arg)
  {
    this->led1 = _arg;
    return *this;
  }
  Type & set__led2(
    const int16_t & _arg)
  {
    this->led2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::LEDLocations_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::LEDLocations_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::LEDLocations_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::LEDLocations_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__LEDLocations
    std::shared_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__LEDLocations
    std::shared_ptr<custom_msgs::msg::LEDLocations_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LEDLocations_ & other) const
  {
    if (this->isled1 != other.isled1) {
      return false;
    }
    if (this->isled2 != other.isled2) {
      return false;
    }
    if (this->led1 != other.led1) {
      return false;
    }
    if (this->led2 != other.led2) {
      return false;
    }
    return true;
  }
  bool operator!=(const LEDLocations_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LEDLocations_

// alias to use template instance with default allocator
using LEDLocations =
  custom_msgs::msg::LEDLocations_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__LED_LOCATIONS__STRUCT_HPP_
