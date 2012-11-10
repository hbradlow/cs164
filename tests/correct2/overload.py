def f(x):
    return x+3
def f(x::string):
    return x
def g(y):
    return y
def g(y::int):
    return y

a = f(g(3))
