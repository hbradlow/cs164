for i in [1, 2, 3]:
    if i == 1:
        break
    print "Fail"
    
a = 0
while a < 3:
    a = a + 1
    break
    print "Fail"
