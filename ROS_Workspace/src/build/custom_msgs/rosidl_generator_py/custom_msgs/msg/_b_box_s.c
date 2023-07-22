// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_msgs:msg/BBox.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_msgs/msg/detail/b_box__struct.h"
#include "custom_msgs/msg/detail/b_box__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__string__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__string__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__string__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__string__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool custom_msgs__msg__b_box__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[28];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_msgs.msg._b_box.BBox", full_classname_dest, 27) == 0);
  }
  custom_msgs__msg__BBox * ros_message = _ros_message;
  {  // top_left_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "top_left_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->top_left_x = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // top_left_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "top_left_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->top_left_y = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // bottom_right_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "bottom_right_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->bottom_right_x = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // bottom_right_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "bottom_right_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->bottom_right_y = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // score
    PyObject * field = PyObject_GetAttrString(_pymsg, "score");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->score = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // class_label
    PyObject * field = PyObject_GetAttrString(_pymsg, "class_label");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__string__convert_from_py(field, &ros_message->class_label)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // px_to_mm
    PyObject * field = PyObject_GetAttrString(_pymsg, "px_to_mm");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->px_to_mm = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // px_to_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "px_to_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->px_to_ms = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // timestamp_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp_ms = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // box_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "box_id");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__string__convert_from_py(field, &ros_message->box_id)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_msgs__msg__b_box__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BBox */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_msgs.msg._b_box");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BBox");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_msgs__msg__BBox * ros_message = (custom_msgs__msg__BBox *)raw_ros_message;
  {  // top_left_x
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->top_left_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "top_left_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // top_left_y
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->top_left_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "top_left_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bottom_right_x
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->bottom_right_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bottom_right_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bottom_right_y
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->bottom_right_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bottom_right_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // score
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->score);
    {
      int rc = PyObject_SetAttrString(_pymessage, "score", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // class_label
    PyObject * field = NULL;
    field = std_msgs__msg__string__convert_to_py(&ros_message->class_label);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "class_label", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // px_to_mm
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->px_to_mm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "px_to_mm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // px_to_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->px_to_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "px_to_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->timestamp_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // box_id
    PyObject * field = NULL;
    field = std_msgs__msg__string__convert_to_py(&ros_message->box_id);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "box_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
