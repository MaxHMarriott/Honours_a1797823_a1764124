# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/LEDLocations.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LEDLocations(type):
    """Metaclass of message 'LEDLocations'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msgs.msg.LEDLocations')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__led_locations
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__led_locations
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__led_locations
            cls._TYPE_SUPPORT = module.type_support_msg__msg__led_locations
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__led_locations

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LEDLocations(metaclass=Metaclass_LEDLocations):
    """Message class 'LEDLocations'."""

    __slots__ = [
        '_isled1',
        '_isled2',
        '_led1x',
        '_led2x',
        '_led1y',
        '_led2y',
    ]

    _fields_and_field_types = {
        'isled1': 'boolean',
        'isled2': 'boolean',
        'led1x': 'float',
        'led2x': 'float',
        'led1y': 'float',
        'led2y': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.isled1 = kwargs.get('isled1', bool())
        self.isled2 = kwargs.get('isled2', bool())
        self.led1x = kwargs.get('led1x', float())
        self.led2x = kwargs.get('led2x', float())
        self.led1y = kwargs.get('led1y', float())
        self.led2y = kwargs.get('led2y', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.isled1 != other.isled1:
            return False
        if self.isled2 != other.isled2:
            return False
        if self.led1x != other.led1x:
            return False
        if self.led2x != other.led2x:
            return False
        if self.led1y != other.led1y:
            return False
        if self.led2y != other.led2y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def isled1(self):
        """Message field 'isled1'."""
        return self._isled1

    @isled1.setter
    def isled1(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'isled1' field must be of type 'bool'"
        self._isled1 = value

    @property
    def isled2(self):
        """Message field 'isled2'."""
        return self._isled2

    @isled2.setter
    def isled2(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'isled2' field must be of type 'bool'"
        self._isled2 = value

    @property
    def led1x(self):
        """Message field 'led1x'."""
        return self._led1x

    @led1x.setter
    def led1x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'led1x' field must be of type 'float'"
        self._led1x = value

    @property
    def led2x(self):
        """Message field 'led2x'."""
        return self._led2x

    @led2x.setter
    def led2x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'led2x' field must be of type 'float'"
        self._led2x = value

    @property
    def led1y(self):
        """Message field 'led1y'."""
        return self._led1y

    @led1y.setter
    def led1y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'led1y' field must be of type 'float'"
        self._led1y = value

    @property
    def led2y(self):
        """Message field 'led2y'."""
        return self._led2y

    @led2y.setter
    def led2y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'led2y' field must be of type 'float'"
        self._led2y = value
