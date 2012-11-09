# The standard prelude.

# NOTE: You may want to phase this in gently, with just a portion of the
#       definitions at first, to keep the sizes of your trees under control
#       during development.

# The __init__ methods of all builtin classes call a function that causes
# a fatal error.

class int:
    pass

class bool:
    pass

class str:
    pass
def __getitem__(S, k):
    native "__getitem__str__"
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


