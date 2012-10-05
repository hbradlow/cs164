def foo(a)::int:
    return 3
def bar(a)::list of [int,string]:
    return [3,"hello"]
def baz(a):
    def test(c):
        return c+4
    return test

print foo(1)
print bar(1)
print baz(1)(5)
