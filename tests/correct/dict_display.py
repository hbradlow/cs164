a = {"hello":1,"goodbye":3}
print a
b = {"dict":a,"list":[1,2,3],"tuple":(4,5,6,),"int":9,"string":"this"}
print b
def foo():
    print "FUNCTION"
c = {"func":foo}
print c['func']()
