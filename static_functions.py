def make_adder(n::int)::(int)->int:
    def adder(x):
        result::int = x + n
        return result
    return adder

f::(int)->int = make_adder(2)
print f(3)
