def foo(x::int):
    return x + 10

def foo(x::str):
    return x + 'hello'

x = foo('goodbye')
