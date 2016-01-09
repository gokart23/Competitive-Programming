import random

f = open("input2.txt", "w")
for i in range(100):
	f.write(str(random.randint(-30000, 30000))+"\n")
f.close()