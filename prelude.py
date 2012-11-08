# The standard prelude.

# NOTE: You may want to phase this in gently, with just a portion of the
#       definitions at first, to keep the sizes of your trees under control
#       during development.

# The __init__ methods of all builtin classes call a function that causes
# a fatal error.

class int:
    def __init__(self::int):
        native "__donotcall__"

class bool:
    def __init__(self::bool):
        native "__donotcall__"

class str:
    def __init__(self::str):
        native "__donotcall__"

class range:
    def __init__(self::range):
        native "__donotcall__"

class file:
    def __init__(self::file):
        native "__donotcall__"

class list of [$T]:
    def __init__(self::list of [$T]):
        native "__donotcall__"

class dict of [$Key, $Value]:
    def __init__(self::dict of [$Key, $Value]):
        native "__donotcall__"

class tuple0:
    def __init__(self::tuple0):
        native "__donotcall__"

class tuple1 of [$T0]:
    def __init__(self::tuple0):
        native "__donotcall__"

class tuple2 of [$T1, $T2]:
    def __init__(self::tuple0):
        native "__donotcall__"

class tuple3 of [$T1, $T2, $T3]:
    def __init__(self::tuple0):
        native "__donotcall__"

# The value None.  References to None are converted to calls __None__().

def __None__():
    native "__None__"

# Type bool

# truth replaces bool(...) in regular Python.  truth(x) is True iff x is a
# true value, according to the Python spec.

def truth(x)::bool:
    native "__truth__"

def __not__(x)::bool:
    native "__not__"

True::bool = truth(1)
False::bool = truth(0)

# Type range

def xrange(low::int, high::int)::range:
    native "__xrange__"

def len(r::range)::int:
    native "__len__range"

# Type int

def __add__(x:: int, y::int)::int:
    native "__add__int"

def __sub__(x::int, y::int)::int:
    native "__sub__int"

def __mul__(x::int, y::int)::int:
    native "__mul__int"

def __floordiv__(x::int, y::int)::int:
    native "__floordiv__int"

def __mod__(x::int, y::int)::int:
    native "__mod__int"

def __pow__(x::int, y::int)::int:
    native "__pow__int"

def __neg__(x::int)::int:
    native "__neg__int"

def __pos__(x::int)::int:
    native "__pos__int"

def __lt__(x::int, y::int)::bool:
    native "__lt__int"

def __gt__(x::int, y::int)::bool:
    native "__gt__int"

def __le__(x::int, y::int)::bool:
    native "__le__int"

def __ge__(x::int, y::int)::bool:
    native "__ge__int"

def __eq__(x::int, y::int)::bool:
    native "__eq__int"

def __ne__(x::int, y::int)::bool:
    native "__ne__int"

# toint is the replacement for 'int' as a function in our dialect.
def toint(x::str)::int:
    native "__toint__str"

# Type str

def __add__(x:: str, y::str)::str:
    native "__add__str"

def __mul__(x::str, y::int)::str:
    native "__lmul__str"

def __mul__(x::int, y::str)::str:
    native "__rmul__str"

def __lt__(x::str, y::str)::bool:
    native "__lt__str"

def __gt__(x::str, y::str)::bool:
    native "__gt__str"

def __le__(x::str, y::str)::bool:
    native "__le__str"

def __ge__(x::str, y::str)::bool:
    native "__ge__str"

def __eq__(x::str, y::str)::bool:
    native "__eq__str"

def __ne__(x::str, y::str)::bool:
    native "__ne__str"

def __getitem__(S::str, k::int)::str:
    native "__getitem__str"

def __getslice__(S::str, L::int, U::int)::str:
    native "__getslice__str"

def len(S::str)::int:
    native "__len__str"

# tostr is the replacement for 'str' as a function in our dialect.
def tostr(x)::str:
    native "__tostr__"

# Type list

def __getitem__(S::list of $a, k::int)::$a:
    native "__getitem__list"

def __getslice__(S::list of $a, L::int, U::int)::list of $a:
    native "__getslice__list"

def len(S::list of $a)::int:
    native "__len__list"

def __argv__()::list of str:
    native "__argv__"

# Type file

def open(name::str)::file:
    native "__open1__"

def open(name::str, mode::str)::file:
    native "__open2__"

def close(f::file):
    native "__close__"

def __standard_file(k::int):
    native "__standard_file"

def readline(f::file)::str:
    native "__readline__"

def read(f::file)::str:
    native "__read__"

# The module sys.
# (We fake this with an instance of a class, using instance variables instead
# of module members.)

class __sys__:
    stdin::file = __standard_file(0)
    stdout::file = __standard_file(1)
    stderr::file = __standard_file(2)

    argv::list of str = __argv__()

sys::__sys__ = __sys__()

# Type dict

def __getitem__(D::dict of [$a, $b], x::$a)::$b:
    native "__getitem__dict"

def len(D::dict of [$a, $b])::int:
    native "__len__dict"

# Backwards from regular Python
def __contains__(x::$a, D::dict of [$a, $b])::bool:
    native "__contains__dict"

# Backwards from regular Python
def __notcontains__(x::$a, D::dict of [$a, $b])::bool:
    native "__notcontains__dict"


# General

def __is__(x, y)::bool:
    native "__is__"

def __isnot__(x, y)::bool:
    native "__isnot__"

