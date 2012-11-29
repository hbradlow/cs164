def g(x):
    return x<=0
def f(x):
    if g(x):
        return x
    else:
        return f(x-1)
print f(3)
