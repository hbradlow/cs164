for i in [1, 2, 3]:
    if True:
        continue
    print "Fail"
        
a = 0
while a < 3:
    if a == 1:
        a = a + 1
        continue
    if a == 1:
        print "Fail"
    if a != 1:
        print "Pass"
    a = a + 1
