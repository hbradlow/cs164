x = 1
y = 3
g = 4
if x == 1:
    print 5
    if y == 2 and g == 2:
        pass
    elif y == 3:
        print 1
        print 2
        if g == 1:
            print 'g'
        else:
            print 'no'
    elif y == 4:
        pass
    else:
        if True:
            pass
        else:
            print 2
elif x == 3:
    print "foo"
else:
    pass
