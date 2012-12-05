def fact(x):
    if x<=1:
        return 1
    else:
        y = fact(x-1)*x
        return y
def fact2(x):
    return (1 if x<=1 else fact(x-1)*x)
print fact(5)
print fact2(5)
