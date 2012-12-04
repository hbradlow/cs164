class A:
    a = 1
    b = "hello"
    d = True
    
    def get_x(self):
        return self.a
    def get_y(self::A):
        return self.b
    def get_w(self):
        return self.d

    def set_x(self,a):
        self.a = a
    def set_y(self::A,b):
        self.b = b
    def set_w(self,d):
        self.d = d

a = A()

a.set_x(1)
a.set_y("hello")
a.set_w(True)

e = a.get_x()
f = a.get_y()
h = a.get_w()
print e
print f
print h

a.set_x(2)
a.set_y("slkj")
a.set_w(False)

e = a.get_x()
f = a.get_y()
h = a.get_w()
print e
print f
print h
