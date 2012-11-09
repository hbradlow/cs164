# More deeply nested scopes

x = 3

def f (x::int):
    x = x + 2
    def g ():
        x = 3
        print x, y
    y = 1
    g ()
    print x

print x

f (10)

print x
