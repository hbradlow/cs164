def foo():
    print 1

def bar(x):
    print x

def foobar(x, y):
    bar(y)
    def barfoo(z):
        print x + z

foo()
foobar(1, 2)
