for i in [1,2,3]: print 1

for a in []:
    print 1

for a in (1,2):
    print 1
else:
    print 2
    print 3

b = {'a':1}
a = {}
for a['a'] in b:
    print 1

for a[1] in []:
    print 1
else:
    print "lawl"

class Foo:
    def __init__(self):
        self.foo = 1

obj = Foo()
obj2 = Foo()
listFoo = [obj, obj2]
b = Foo()
for b.foo in listFoo:
    print 1

