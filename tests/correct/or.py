a = 3
b = 5
def foo():
    return 5
c = a or b
c = c or b
c = foo() or c
