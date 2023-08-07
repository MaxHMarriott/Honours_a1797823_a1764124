# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/FireSeverity.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FireSeverity(type):
    """Metaclass of message 'FireSeverity'."""

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
                'custom_msgs.msg.FireSeverity')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fire_severity
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fire_severity
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fire_severity
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fire_severity
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fire_severity

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FireSeverity(metaclass=Metaclass_FireSeverity):
    """Message class 'FireSeverity'."""

    __slots__ = [
        '_severity',
        '_isdetected',
        '_fire_x',
        '_fire_y',
    ]

    _fields_and_field_types = {
        'severity': 'string',
        'isdetected': 'boolean',
        'fire_x': 'float',
        'fire_y': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.severity = kwargs.get('severity', str())
        self.isdetected = kwargs.get('isdetected', bool())
        self.fire_x = kwargs.get('fire_x', float())
        self.fire_y = kwargs.get('fire_y', float())

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
        if self.severity != other.severity:
            return False
        if self.isdetected != other.isdetected:
            return False
        if self.fire_x != other.fire_x:
            return False
        if self.fire_y != other.fire_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def severity(self):
        """Message field 'severity'."""
        return self._severity

    @severity.setter
    def severity(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'severity' field must be of type 'str'"
        self._severity = value

    @property
    def isdetected(self):
        """Message field 'isdetected'."""
        return self._isdetected

    @isdetected.setter
    def isdetected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'isdetected' field must be of type 'bool'"
        self._isdetected = value

    @property
    def fire_x(self):
        """Message field 'fire_x'."""
        return self._fire_x

    @fire_x.setter
    def fire_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fire_x' field must be of type 'float'"
        self._fire_x = value

    @property
    def fire_y(self):
        """Message field 'fire_y'."""
        return self._fire_y

    @fire_y.setter
    def fire_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fire_y' field must be of type 'float'"
        self._fire_y = value
