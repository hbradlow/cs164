def f():
    def g():
        return 3
    return g
b = f()
c = b()
