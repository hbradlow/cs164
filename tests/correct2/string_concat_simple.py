x::str = 'hello'
y = 'goodbye ' + x

def foo(x::str):
    return x + 'str'

z::str = foo('stringtest')
