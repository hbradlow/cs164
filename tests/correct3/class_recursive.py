class A:
    def f(self,x):
        if x==0:
            return "hello"
        return self.g(x-1)
    def g(self,x):
        if x==0:
            return 3
        return self.f(x-1)
a = A()
print a.f(4)
print a.f(3)
