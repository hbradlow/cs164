class a:
    def g(self):
        print "HERE"
b = a.g
b(a())
