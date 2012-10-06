b, c, d = [1,2,3,4,5],1,4
for i in b[c:d]:
    print i
    for e in b[:]:
        print e; print e+1
for i in b[c:]:
    print i
for i in b[:d-1]:
    print i
c = b[:]
print c, b[d-3:d +1]

