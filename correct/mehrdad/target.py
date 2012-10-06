(a, b) = (True, False)
print a, b

a, b = (True, False)
print a, b

[a, b, c, d] = [True, False, True, False]
print a, b, c, d

a = [1, 2, 3]
a[1:2] = [1]
print a

a = {1: 2}
a[1] = 3
print a

class Test:
	def __init__(self):
		self.x = 1
a = Test()
a.x = 2
print a.x
