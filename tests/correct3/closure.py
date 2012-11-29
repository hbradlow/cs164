def f(x):
    def g():
        return x+3
    return g
print f(2)()
