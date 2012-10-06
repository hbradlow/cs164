def foo(a::blah):
    print 1
foo(1)

def foo(a::int, b, c::$lol)::int:
    print 1
foo(1,2,3)

def foo(a,b)::(int)->int:
    print 2
foo(1,2)

def foo10(a::list of int):
    print a
foo10("lol")

def foo2(a::list of [int]):
    print a
foo2('a')

def foo2(a::lol)::(int,$lol)->(int,int)->lol:
    print 1
foo2(1)

def foo3(a::$hi, b, c::lol)::(int,$lol)->$int:
    1
foo3(1,2,3)

def foo5(a::lol)::(list of [int,$blah])->(int,char,$lol)->int:
    print 11
foo5(1)

def foo6(a::lol)::(list of [int, $blah, list of [$T,int]])->(int,char,$lol)->int:
    print 11
foo6(1)

def foo5(a::lol)::()->int:
    print 11
foo5(2)
