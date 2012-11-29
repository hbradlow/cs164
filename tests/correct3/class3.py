class A:
    a = 1
    b = "hello"
    c::file = __standard_file__(0)
    d = True
    
    def get_x(self):
        return self.a
    def get_y(self::A):
        return self.b
    def get_z(self)::file:
        return self.c
    def get_w(self):
        return self.d

    def set_x(self,a):
        self.a = a
    def set_y(self::A,b):
        self.b = b
    def set_z(self,c):
        self.c = c
    def set_w(self,d):
        self.d = d

a = A()
e = a.get_x()
f = a.get_y()
g = a.get_z()
h = a.get_w()
print e
print f
#print g #not sure what this does...
print h

a.set_x(2)
a.set_y("slkj")
a.set_z(__standard_file__(1))
a.set_w(False)

print e
print f
#print g #not sure what this does...
print h
