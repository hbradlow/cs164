def returnTrue():
    return True
    
def returnFalse():
    return False
    
if returnTrue():
    if not returnFalse():
        print "Pass"
    else:
        print "Fail"
else:
    print "Fail"
