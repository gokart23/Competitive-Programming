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
                break
        if m:
            numD += 1
        
    if numD < dishesReq:
        return numD,False
    else:
        return numD,cost

'''def randomSample(m, n):
    if m <= 0:
        return []
    else:
        S = randomSample(int(m-1), n-1 if n-1>0 else 0)
        i = random.randint(0, n-1 if n-1>0 else 0)
        if i in S:
            S.append(n)
        else: S.append(i)
        return S'''
def randomSample(m, n):
    r = range(n)
    for i in range(m-1):
        a = random.randint(0, n-1) if n-1>0 else 0
        print a,i
        r[a],r[i]=r[i],r[a]
        n -= 1
    return r[-m:]

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
perms = [[] for x in range(10)]
lengths = [x for x in range(10)]
scores = [0 for x in range(10)]
strg=""
for l in range(len(perms)):
    ln = random.randint(lengths[l]*numPeople/10,(lengths[l]+1)*numPeople/10+1)
    perms[l] = randomSample(ln, numPeople) if ln != 0 else []
    strg += str(perms[l]) + " "
print strg
bestSoFar,bestScore=None,float("inf")
for j in range(10):        
    for i in range(20):
        strg = ""
        for l in range(len(perms)):
            a,b=numberOfDishes(perms[l]) if len(perms[l]) != 0 else 0,0
            if b != False and b < bestScore and len(perms[l]) != 0:
                bestSoFar = copy.copy(perms[l])
                bestScore = b
            scores[l]+=b
            ln = random.randint(lengths[l]*numPeople/10,(lengths[l]+1)*numPeople/10+1)
            perms[l] = randomSample(ln, numPeople) if ln != 0 else []
            strg += str(perms[l])+str(b)+" "
        print strg
    print "max:",max(scores)/20,scores.index(max(scores)),"min:",min(scores)/20,scores.index(min(scores))
    print "bestSoFar:",str(bestSoFar),bestScore
    lengths[scores.index(max(scores))] = lengths[scores.index(min(scores))]