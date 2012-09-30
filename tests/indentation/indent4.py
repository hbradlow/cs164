def foo(x):
    if x == 1:
      return x
 else:
     return x * foo(x-1)

def bar(y):
            if foo(y) > 10:
             print 'foo'
            else:
                    print 'bar'

