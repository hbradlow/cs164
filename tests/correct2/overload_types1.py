class C:
    x = 0
    def __init__(self):
        self.x = 10

def foo(int::x):
    print x

def foo(str::x):
    print x

def foo(C::x):
    print x
