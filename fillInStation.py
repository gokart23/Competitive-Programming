bigram = [{}]
c = []
with open('bigram.txt', 'r') as f:
	string = f.readline()
	while string != "":
		b = string.split()
		