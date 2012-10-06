a = (1, 2,3, 4, 5,6,7)
b, c, d, e, f,g, h = a
print b, c, d, e, f, g, h

c, d, e, f, b, i, k = a
print b, c, d, e, f, i, k

a = (1, 4, 5, (2, 3))
g, z, x, atup = a
first, second = atup
print g, first, second, z, x
