import random,copy

def getPathDist(perm):
    pathDist=0
    for i in range(len(perm)-1):
        pathDist += distances[perm[i]][perm[i+1]]
    pathDist += distances[perm[len(perm)-1]][perm[0]]
    return pathDist

numCities = input()
cities = {0:(0,0,0)}
for i in range(numCities):
    vals = raw_input().split(",")
    cities[i+1] = (float(vals[1]),float(vals[2]),float(vals[3]))
print cities
distances = [[] for x in cities]
for i in range(len(cities)):
    distances[i] = [(cities[i][0] - cities[x][0])**2 + (cities[i][1] - cities[x][1])**2 + (cities[i][2] - cities[x][2])**2 for x in cities]
print distances
perm = [x for x in range(numCities+1)]

for i in range(numCities):
    t = random.randint(i+1,numCities)
    perm[i],perm[t]=perm[t],perm[i]

numIter,numOperations=500,0
bestSoFar=copy.copy(perm)
pathDist = getPathDist(perm)
bestDist = getPathDist(perm)
print "Init distance:",pathDist," init perm:",perm

for i in range(numIter):
    t,r=0,0
    while t == r:
        t,r = random.randint(0, numCities), random.randint(0, numCities)    
    if t > r:
        t,r=r,t
    perm[t],perm[r]=perm[r],perm[t]    
    newDist = getPathDist(perm)
    print "posns:",t,r,newDist,pathDist
    if newDist < pathDist:
        bestSoFar=copy.copy(perm)
        pathDist = newDist
        print "New path chosen",perm        
    else:
        if random.random() < 0.25:
            '''if getPathDist(bestSoFar) > pathDist:
                perm[t],perm[r]=perm[r],perm[t]
                bestSoFar=copy.copy(perm)
            pathDist = newDist
            print "New BAD path chosen",perm'''
            perm[t],perm[r] = perm[r],perm[t]
            pass
        else:       
            perm[t],perm[r]=perm[r],perm[t]
            print "Path not chosen",perm
    print "------"
'''    newDist = pathDist - distances[perm[t]][perm[t+1]] - distances[perm[t]][perm[t-1]]
    if r == len(perm)-1:
        newDist -= (distances[perm[r]][perm[r-1]] + distances[perm[r]][perm[0]])
    else:
        newDist -= (distances[perm[r]][perm[r+1]] + distances[perm[r]][perm[r-1]])
    if abs(t-r)==0 or abs(t-r)==numCities:
        newDist += distances[perm[t]][perm[r]]
    print "newDist:",newDist'''
print bestSoFar,getPathDist(bestSoFar)