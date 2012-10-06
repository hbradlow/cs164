class PriorityList1 of [$ItemType]:
	def __init__(self):
		self.items = []
		self.d = { "key": [ [ None ] ] }

class PriorityList2 of [$ItemType, 2]:
	pass

pq1 = PriorityList1 of int()
pq1 = PriorityList1 of [int]() 
pq2 = PriorityList2 of [int, int]()

