def b(int)::string:
    return "Hello"
a::(int)->string = b
print a(3)

class Foo of [int,string]:
    x = 0
a = Foo of int(3)
print a.x
