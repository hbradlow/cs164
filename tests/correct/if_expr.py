a = False
b = True
def foo():
    print "Hey"
print "hello" if True else "bye"
print "hello" if a else "bye"
print "hello" if b else "bye"
print a if b else "bye"
print a if b else b
print a if b else foo()
