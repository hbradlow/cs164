def fact(x::int):
    return (1 if x<=1 else fact(x-1)*x)
print fact(5)
