# Attempt to assign to nonexistent field of class instance.

class A:
    def f(self, x):
        self.y = x
