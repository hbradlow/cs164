def foo(x):
    def bar(y):
        print x, y
    bar(10)
foo(9)
