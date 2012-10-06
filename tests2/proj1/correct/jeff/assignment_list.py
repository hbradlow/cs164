a = [1,2,3]
print a
a[2] = 5
print a
a[0] = 10
print a
a = [1,2,[1,2,[1,2]]]
print a
a[2][0] = 30000
print a
a[-1] = 5
print a
a[-2] = 5
print a
a[-3] = 5
print a
print a[:1]
a[0] = a[:]
print a
