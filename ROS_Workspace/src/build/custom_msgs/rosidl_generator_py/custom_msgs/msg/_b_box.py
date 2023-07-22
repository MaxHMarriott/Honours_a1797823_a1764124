# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/BBox.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BBox(type):
    """Metaclass of message 'BBox'."""

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
                'custom_msgs.msg.BBox')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__b_box
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__b_box
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__b_box
            cls._TYPE_SUPPORT = module.type_support_msg__msg__b_box
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__b_box

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BBox(metaclass=Metaclass_BBox):
    """Message class 'BBox'."""

    __slots__ = [
        '_top_left_x',
        '_top_left_y',
        '_bottom_right_x',
        '_bottom_right_y',
        '_score',
        '_class_label',
        '_px_to_mm',
        '_px_to_ms',
        '_timestamp_ms',
        '_box_id',
    ]

    _fields_and_field_types = {
        'top_left_x': 'uint32',
        'top_left_y': 'uint32',
        'bottom_right_x': 'uint32',
        'bottom_right_y': 'uint32',
        'score': 'float',
        'class_label': 'std_msgs/String',
        'px_to_mm': 'float',
        'px_to_ms': 'float',
        'timestamp_ms': 'uint64',
        'box_id': 'std_msgs/String',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.top_left_x = kwargs.get('top_left_x', int())
        self.top_left_y = kwargs.get('top_left_y', int())
        self.bottom_right_x = kwargs.get('bottom_right_x', int())
        self.bottom_right_y = kwargs.get('bottom_right_y', int())
        self.score = kwargs.get('score', float())
        from std_msgs.msg import String
        self.class_label = kwargs.get('class_label', String())
        self.px_to_mm = kwargs.get('px_to_mm', float())
        self.px_to_ms = kwargs.get('px_to_ms', float())
        self.timestamp_ms = kwargs.get('timestamp_ms', int())
        from std_msgs.msg import String
        self.box_id = kwargs.get('box_id', String())

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
        if self.top_left_x != other.top_left_x:
            return False
        if self.top_left_y != other.top_left_y:
            return False
        if self.bottom_right_x != other.bottom_right_x:
            return False
        if self.bottom_right_y != other.bottom_right_y:
            return False
        if self.score != other.score:
            return False
        if self.class_label != other.class_label:
            return False
        if self.px_to_mm != other.px_to_mm:
            return False
        if self.px_to_ms != other.px_to_ms:
            return False
        if self.timestamp_ms != other.timestamp_ms:
            return False
        if self.box_id != other.box_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def top_left_x(self):
        """Message field 'top_left_x'."""
        return self._top_left_x

    @top_left_x.setter
    def top_left_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'top_left_x' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'top_left_x' field must be an unsigned integer in [0, 4294967295]"
        self._top_left_x = value

    @property
    def top_left_y(self):
        """Message field 'top_left_y'."""
        return self._top_left_y

    @top_left_y.setter
    def top_left_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'top_left_y' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'top_left_y' field must be an unsigned integer in [0, 4294967295]"
        self._top_left_y = value

    @property
    def bottom_right_x(self):
        """Message field 'bottom_right_x'."""
        return self._bottom_right_x

    @bottom_right_x.setter
    def bottom_right_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'bottom_right_x' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'bottom_right_x' field must be an unsigned integer in [0, 4294967295]"
        self._bottom_right_x = value

    @property
    def bottom_right_y(self):
        """Message field 'bottom_right_y'."""
        return self._bottom_right_y

    @bottom_right_y.setter
    def bottom_right_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'bottom_right_y' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'bottom_right_y' field must be an unsigned integer in [0, 4294967295]"
        self._bottom_right_y = value

    @property
    def score(self):
        """Message field 'score'."""
        return self._score

    @score.setter
    def score(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'score' field must be of type 'float'"
        self._score = value

    @property
    def class_label(self):
        """Message field 'class_label'."""
        return self._class_label

    @class_label.setter
    def class_label(self, value):
        if __debug__:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'class_label' field must be a sub message of type 'String'"
        self._class_label = value

    @property
    def px_to_mm(self):
        """Message field 'px_to_mm'."""
        return self._px_to_mm

    @px_to_mm.setter
    def px_to_mm(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'px_to_mm' field must be of type 'float'"
        self._px_to_mm = value

    @property
    def px_to_ms(self):
        """Message field 'px_to_ms'."""
        return self._px_to_ms

    @px_to_ms.setter
    def px_to_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'px_to_ms' field must be of type 'float'"
        self._px_to_ms = value

    @property
    def timestamp_ms(self):
        """Message field 'timestamp_ms'."""
        return self._timestamp_ms

    @timestamp_ms.setter
    def timestamp_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp_ms' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'timestamp_ms' field must be an unsigned integer in [0, 18446744073709551615]"
        self._timestamp_ms = value

    @property
    def box_id(self):
        """Message field 'box_id'."""
        return self._box_id

    @box_id.setter
    def box_id(self, value):
        if __debug__:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'box_id' field must be a sub message of type 'String'"
        self._box_id = value
