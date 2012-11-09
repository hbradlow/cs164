# Test that correct typings are allowed without type attributions.

x = 5
y = "foo"
z1 = []
z2 = [1,2,3]
b = { 1 : "foo" }

xt::int = x
yt::str = y
z2t::list of int = z2
bt::dict of [int, str] = b

u = 13

x = 3 or 5
x = 3 and 5

x = 4 if z1 else 5

x = u

