class A:
    q = 7
    print q
    def __init__(self, n):
        self.q = n
    def r(self, x):
        return self.q + x

class B:
    p = 0
    def sets(self, n):
        self.p = n
    def s(self):
        return self.p

x::B = B()
x.sets(3)
print x.s()

y::A = A(3)
print y.r(77)
