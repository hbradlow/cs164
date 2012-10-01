def foo(bar):
indent    return bar**3
dedent
def baz(x):
indent    return x + 1
dedent
print baz(foo(100))
