for x in [1, 2, 3]:
    print x

def foo():
    return [1, 2, 3]
print foo()

for x in foo():
    print x
