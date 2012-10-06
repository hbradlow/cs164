class Foo of [$K]:
    a = 'blah'
    def __init__(self):
        a::$K = 123

    def foo(self):
        print self.a
a = Foo of int ()
