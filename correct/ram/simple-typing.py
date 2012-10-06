x::int = 1
print x
def foo1(n::int):
    pass
def foo2(n)::int:
    pass
def foo3(n::str)::int:
    pass
a::(str)->int = foo3

class MyMap of [$K, $V]:
    def get(k::$K)::$V:
        return None

    def set(k::$K, v::$V):
        pass

# are these supposed to work?
e = MyMap of [str, int]()
c::list of [int] = [1, 2, 3]

