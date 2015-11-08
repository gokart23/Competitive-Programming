import random,copy,math

def numberOfDishes(perm):
    sets = {}
    for x in skills:
        sets[x]=0
    cost = 0
    for i in perm:
        cost += chefs[i][0]
        for j in xrange(1, len(chefs[i])):
            sets[chefs[i][j]] = sets[chefs[i][j]] + 1
    numD=0
    for d in dishes:
        for e in d:
            m=True
            if sets[e] == 0:
                m=False
        if m:
            numD += 1
        
    if numD < dishesReq:
        return numD,False
    else:
        return numD,cost

vals = raw_input().split()
numDishes,numPeople,dishesReq=int(vals[0]),int(vals[1]),int(vals[2])*int(vals[0])/100
skills,dishes,chefs=set([]),[[] for x in range(numDishes)],[[] for x in range(numPeople)]
for i in range(numDishes):
    v = raw_input().split()
    dishes[i] = [int(x) for x in v]
    for j in dishes[i]:
        if j not in skills:
            skills.add(j)
for i in range(numPeople):
    v = raw_input().split()
    chefs[i] = [int(x) for x in v]
perm = []
numIter,bestSoFar,bestCost=5,None,float("inf")
for x in range(numPeople):
    if(random.random() < 0.01):
        perm.append(x)
for x in range(numIter):
    numD,a = numberOfDishes(perm)
    print "Current perm:",len(perm),a,numD
    if a != False and a < bestCost:
        bestSoFar,bestCost = copy.copy(perm),a
    temp = []
    
    b = (numD-dishesReq)/float(dishesReq)
    if b > 20:
        b = 20
    elif b<-20:
        b = -20
    sigmoid = 1/float(1 + math.exp(-b))
    print sigmoid*(float(9)/10),"sigmoid"
    for x in range(numPeople):
        if x in perm and random.random() < sigmoid*(float(9)/10): 
            temp.append(x)           
        elif random.random() < sigmoid*(float(4)/10):
            temp.append(x)
    perm = copy.copy(temp)
    print perm
    print "perm length:",len(perm)

print bestSoFar,bestCost