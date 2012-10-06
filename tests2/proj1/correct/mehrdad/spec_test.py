def f(n):
	i::int = 0
	while i <= n:
		if 1 < i % 7 <= 2:
			print i + 1,
		i = i + 1
	else:
		s = i + 2
		t = (1 if True else t if True else i) + s ** 2
		print "s =", s, "t =", t
	list1 = {}
	list2 = {True: 1}
	for somelist in list1, list2:
		print somelist
		somelist[1, 2, 3] = 5    # error!

print f(4)

