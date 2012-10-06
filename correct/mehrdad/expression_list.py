def SideEffect(x):
	print 'side effect'
	return x

print SideEffect(True) or SideEffect(False) and SideEffect(True)
print SideEffect(True) or SideEffect(True) and SideEffect(True)
