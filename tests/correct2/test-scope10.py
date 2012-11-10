# Try redefining things other than variables

def func1 (x::int):
    func2 = 13 + x
    return func2


def func2 (func1:: ()->int):
    x::int = 19
    q::int = func1 ()
    return q + x

def x()::int:
    return 42
print func2 (x)
