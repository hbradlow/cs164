def f():
    a = 3
    b = a*3
    c = b*3
    return c
def g():
    a = f()
    return a*2
print g()
