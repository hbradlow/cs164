# Test that correct typings are allowed.

x::int = 5
y::str = "foo"
z1::list of int = []
z2::list of int = [1,2,3]
b::dict of [int, str] = { 1 : "foo" }

u = 13

x = 3 or 5
x = 3 and 5

x = 4 if z1 else 5

x = u
