# Short circuiting

def shouldNotPrint()::int:
    print "This should not be printed"
    return 42

0 and shouldNotPrint()
