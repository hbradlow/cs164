def g(x):
    return x<1
def f(x):
    if g(x):
        return x
    else:
        return f(x-1)
print f(3)
