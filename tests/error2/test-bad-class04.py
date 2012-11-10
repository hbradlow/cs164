# Make sure we can't call undefined methods

class A:
    pass

A().f(21)
