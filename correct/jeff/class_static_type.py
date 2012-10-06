class Foo of [$lol,$blah]:
    def foo(self):
        print 1

foo = Foo of [int,str]()
boo::Foo of [hilfinger] = Foo of [int]()
foo.foo()

class Foo of [$lol]:
    def foo(self):
        print 1

foo = Foo()
foo.foo()

class Foo2 of [$blah,$foo,$lol]:
    def foo(self):
        print 2

foo2 = Foo2()
foo2.foo()

class Foo3 of [$blah,$foo,$lol]:
    def foo(self):
        print 3

foo3 = Foo3()
foo3.foo()

class Foo4 of [$lol]:
    a::int = 3
    def foo(self):
        print 3

foo4 = Foo4()
print foo4.a
foo4.foo()
