z = 3, 6, 56, (9, 12), 

(a, b, c, d) = z
print a, b, c, d

a = b = c = d = 78

(b, a, e, y) = z
(c, d) = y
print a, b, c, d

a, b, c, d = z
print a, b, c, d

b, a, y, e = z
c, d = e
print a, b, c, d, e

[a, b, c, d] = z
print a, b, c, d

[b, a, e, y] = z
c, d = y
print a, b, c, d, e
