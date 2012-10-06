def foo(bar):
    if bar % 2 == 1:
        print 'odd'
        if bar == 1:
            print 'one'
    else:
        print 'even'

foo(1)
foo(3)
foo(0)
