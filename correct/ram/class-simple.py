class A:
    def __init__(self):
        print "hi"
    def bar(self, x):
        print "in bar"
        if x < 10:
            print "smaller than 10"
        else:
            print "bigger than 10"

a = A()

