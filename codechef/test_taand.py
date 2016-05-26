from random import randint

vals = [randint(0, 100000) for i in range(randint(2, 500))]
maxv, max_num = 0, []
print len(vals)
for i in range(len(vals)):
	print vals[i]
	for j in range(i+1, len(vals)):
		if (vals[i] & vals[j]) > maxv:
			maxv, max_num = vals[i] & vals[j], [vals[i], vals[j]]
print "\n\n\n",maxv,max_num