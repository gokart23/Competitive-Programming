import random,copy,math

def getPathDist(perm):
    pathDist=0
    for i in range(len(perm)-1):
        pathDist += distances[perm[i]][perm[i+1]]
    pathDist += distances[perm[len(perm)-1]][perm[0]]
    return pathDist

numCities = input()
wolfVulcan = [-1,-1]
cities = {0:(0,0,0, "Earth")}
for i in range(numCities):
    vals = raw_input().split(",")
    if vals[0] == "Wolf 359" or vals[0] == "Wolf359":
        wolfVulcan[0] = (i+1)
    if vals[0] == "Vulcan":
        wolfVulcan[1] = (i+1)
    cities[i+1] = (float(vals[1]),float(vals[2]),float(vals[3]), vals[0])
#print cities
distances = [[] for x in cities]
for i in range(len(cities)):
    distances[i] = [math.sqrt((cities[i][0] - cities[x][0])**2 + (cities[i][1] - cities[x][1])**2 + (cities[i][2] - cities[x][2])**2) for x in cities]
if wolfVulcan[0] != -1 and wolfVulcan[1] != -1:
    distances[wolfVulcan[0]][wolfVulcan[1]]=distances[wolfVulcan[1]][wolfVulcan[0]]=distances[wolfVulcan[1]][wolfVulcan[0]]/2
 #   print "Vulcan val changed!!"
#print distances
perm = [x for x in range(numCities+1)]

for i in range(numCities):
    t = random.randint(i+1,numCities)
    perm[i],perm[t]=perm[t],perm[i]

numIter,numOperations=50000,0
bestSoFar=copy.copy(perm)
pathDist = getPathDist(perm)
bestDist = getPathDist(perm)
#print "Init distance:",pathDist," init perm:",perm

for i in range(numIter):
    t,r=0,0
    while t == r:
        t,r = random.randint(0, numCities), random.randint(0, numCities)    
    perm[t],perm[r]=perm[r],perm[t]    
    newDist = getPathDist(perm)
#    print "posns:",t,r,newDist,pathDist
    if newDist < pathDist:
        if newDist < bestDist:
            bestSoFar=copy.copy(perm)
            bestDist = newDist
        pathDist = newDist
 #       print "New path chosen",perm
    else:
        if random.random() < math.exp((-1)*(newDist-pathDist)):
            '''if getPathDist(bestSoFar) > pathDist:
                perm[t],perm[r]=perm[r],perm[t]
                bestSoFar=copy.copy(perm)
            pathDist = newDist'''
 #           print "New BAD path chosen",perm
            pathDist = newDist
        else:
            perm[t],perm[r]=perm[r],perm[t]
 #           print "Path not chosen",perm
 #   print "------"
'''    newDist = pathDist - distances[perm[t]][perm[t+1]] - distances[perm[t]][perm[t-1]]
    if r == len(perm)-1:
        newDist -= (distances[perm[r]][perm[r-1]] + distances[perm[r]][perm[0]])
    else:
        newDist -= (distances[perm[r]][perm[r+1]] + distances[perm[r]][perm[r-1]])
    if abs(t-r)==0 or abs(t-r)==numCities:
        newDist += distances[perm[t]][perm[r]]
    print "newDist:",newDist'''
#print bestSoFar
start = bestSoFar.index(0)
dir = -1
if wolfVulcan[0] != -1 and wolfVulcan[1] != -1:
    l = bestSoFar.index(wolfVulcan[0])
    if l-start > 0:
        dir = 1

strRes = ""
if dir == -1:
    for i in range(numCities+1):
        strRes += cities[bestSoFar[(start+numCities+1)%(numCities+1)]][3]+", "
        start -= 1
else:
    for i in range(numCities+1):
        strRes += cities[bestSoFar[start%(numCities+1)]][3]+", "
        start += 1
        
print strRes+"Earth, "+str(getPathDist(bestSoFar))