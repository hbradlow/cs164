class E:
    blah = 5
    
    def f(self):
        print "Class tests: foo"

y = 0

class F:
    class G:
        def f(self):
            print "Class tests: bar"
        
        def __init__(self):
            self.x = y

        class H:
            def f(self):
                print "Class tests: bar"
                def foo(x): x
            
            def __init__(self):
                self.x = y

            x = y
        x = y

    def f(self):
        print "Class tests: bar"
    
    def __init__(self):
        self.x = y

    x = y
