i = 0
while i<10:
    i = i+1
    print "HERE"

def test(a):
    return a==4
i = 0
while not test(i):
    i = i+1
    print "THERE"
