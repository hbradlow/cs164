def f(x):
    y = 10
    def g(y):
        return y
    return g
print f(10)(5)
