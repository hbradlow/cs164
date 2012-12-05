def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

q = factorial(3)
print q
