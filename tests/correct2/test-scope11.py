# Check that we know about things in standard prelude

print None
print True
print False
print len("hello")

r = [1, 2, 3]
q = 4
print truth(0), truth("x")
print toint("12")

f2 = open("/dev/null", "r")
f1 = open("/dev/null")
close(f1)

for i in xrange(0, 2): print i
