# Check that printing to files works.

f::file = sys.stdout

g = sys.stdout

print >> f, "Hello,",
print >> g, "world!"
print >> sys.stdout, "See you later."
