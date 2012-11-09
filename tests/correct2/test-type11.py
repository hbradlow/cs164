# Test that unbound methods are OK to save

class A:
    def f (self):
        return 14

vf::(A)->int = A.f

anA::A = A()

print vf(anA)

L = [A.f]

vf = L[0]

print vf(anA)
