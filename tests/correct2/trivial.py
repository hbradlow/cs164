class int:
    pass
class string:
    pass
def f(a):
    def g():
        pass
    return g
b = f(3)
x = b()
