def foo1(bar):
    return bar
def foo2(bar)::int:
    return 3
def foo3(bar)::list of [int,string]:
    return [3,"hello"]
def foo4(bar)::string:
    return "hello"
print foo1(6)
print foo2(6)
print foo3(6)
print foo4(6)
a::int = foo1(9)
print a
b::list of [int,string] = foo3(6)
print b
