
def bar(x::dict of [str, str]):
    if 'key' not in x:
        x['key'] = 'default'
    return x
def bar(x::int):
    return 0
def foo(x::dict of [str, str]):
    y = bar(x)
    return y['key']

def foo(x::int):
    return 10


