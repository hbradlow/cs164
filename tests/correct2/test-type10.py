# Check that empty returns and missing returns work properly.

def empty_return()::str:
    print "empty return"
    return

def no_return()::str:
    print "no return"

def empty_None_return():
    return

def int_no_return()::int:
    print "empty return of int"

print empty_return()
print no_return()
print empty_None_return()
# We don't print this one, because our value differs from that of regular
# Python.
int_no_return()

