f = open('print_to_file_test.txt','w')
print >> f, 'printing to a file'
f2 = open('print_to_file_test.txt', 'r')
print f2.read()
