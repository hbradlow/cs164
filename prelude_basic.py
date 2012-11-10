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
    def __init__(self::tuple1 of [$a]):
        native "__donotcall__"

class tuple2 of [$T1, $T2]:
    def __init__(self::tuple2 of [$a, $b]):
        native "__donotcall__"

class tuple3 of [$T1, $T2, $T3]:
    def __init__(self::tuple3 of [$a, $b, $c]):
        native "__donotcall__"

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
    native "__len__range__"

# Type int

def __add__(x:: int, y::int)::int:
    native "__add__int__"

def __sub__(x::int, y::int)::int:
    native "__sub__int__"

def __mul__(x::int, y::int)::int:
    native "__mul__int__"
def __mul__(x::str, y::int)::str:
    native "__lmul__str__"

def __floordiv__(x::int, y::int)::int:
    native "__floordiv__int__"

def __mod__(x::int, y::int)::int:
    native "__mod__int__"

def __pow__(x::int, y::int)::int:
    native "__pow__int__"

def __neg__(x::int)::int:
    native "__neg__int__"

def __pos__(x::int)::int:
    native "__pos__int__"

def __lt__(x::int, y::int)::bool:
    native "__lt__int__"

def __gt__(x::int, y::int)::bool:
    native "__gt__int__"

def __le__(x::int, y::int)::bool:
    native "__le__int__"

def __ge__(x::int, y::int)::bool:
    native "__ge__int__"

def __eq__(x::int, y::int)::bool:
    native "__eq__int__"

def __ne__(x::int, y::int)::bool:
    native "__ne__int__"

# toint is the replacement for 'int' as a function in our dialect.
def toint(x::str)::int:
    native "__toint__str__"

#Type str -------------- MISSING

# Type list

def __getitem__(S::list of $a, k::int)::$a:
    native "__getitem__list__"

def __getslice__(S::list of $a, L::int, U::int)::list of $a:
    native "__getslice__list__"

def len(S::list of $a)::int:
    native "__len__list__"

def __argv__()::list of str:
    native "__argv__"

# Type file -------------- MISSING


# The module sys.
# (We fake this with an instance of a class, using instance variables instead
# of module members.)

def __standard_file__(x::int)::file:
    native "__standard_file__"

class __sys__:

    stdin::file = __standard_file__(0)
    stdout::file = __standard_file__(1)
    stderr::file = __standard_file__(2)

    argv::list of str = __argv__()

sys::__sys__ = __sys__()


def __None__():
    native "__None__"
def open(name::str)::file:
    native "__open1__"
def open(name::str, mode::str)::file:
    native "__open2__"
def close(f::file):
    native "__close__"
