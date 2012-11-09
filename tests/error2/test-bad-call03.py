# Attempt to call a method with the wrong number of parameters.

class A:
    def f(self, x):
        pass


A().f()
