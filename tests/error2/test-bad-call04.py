# Attempt to call a method with the wrong number of parameters from within
# a class.

class A:
    def f(self):
        pass

    f(A(), 3)
