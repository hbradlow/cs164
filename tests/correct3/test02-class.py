class A:
    x = 3
    def method1(self):
        print "A's value of x is", self.x

anA = A()
anA.x = 42

print A.x
A.x = 12
print A.x, anA.x

anotherA = A()
print anotherA.x


