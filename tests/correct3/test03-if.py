x = [1, 2]
if x:
    print "Yes1"
else:
    print "No1"

y = []

if y:
    print "No2"
elif x:
    print "Yes2"
else:
    print "No2"

if None:
    print "No3"
else:
    print "Yes3"

if {}:
    print "No4"
elif { 1 : 2 }:
    print "Yes4"
else:
    print "No4"

if "":
    print "No5"
elif "Hi":
    print "Yes5"
else:
    print "No5"

if xrange(0,0):
    print xrange(0,0)
    print "No6"
elif xrange(0,1):
    print "Yes6"
else:
    print "No6"

if ():
    print "No7"
elif (1, 2):
    print "Yes7"
else:
    print "No7"
