class C:
    def foo(self):
        print 'foo'
    def bar(self):
        self.foo()

x = C()
