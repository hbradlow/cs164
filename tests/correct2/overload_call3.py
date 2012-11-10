def foo(x::int, y::str):
    return x + 10

def foo(x::str, y::int):
    return x + 'hello'

x = foo('goodbye')
