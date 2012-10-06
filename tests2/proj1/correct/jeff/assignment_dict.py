a = {'a':1,'b':2}
print a
a = {1:2}.items()
{1:2}[1] = 5
{1:{1:2}}[1][1] = 10
t = {1:{2:3}}
print t
print t[1]
t[1] = 3
print t
print t[1]
z = {(1,2):(1,2)}
print z
z[(1,2)] = [4,5]
print z
