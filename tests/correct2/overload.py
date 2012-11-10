def f(x):
    return x+3
def f(x::str):
    return x
def g(y::str):
    return "hello"
def g(y::int):
    return y

a = f(g("3"))
