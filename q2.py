def getStats(values, prevMean, prevDev):
    differences=[]
    meanDiff,stDev=0,0
    for i in range(len(values) - 1):
        if abs(values[i] - values[i+1]) <= (prevMean + 1*prevDev):
            differences.append(abs(values[i] - values[i+1]))
            meanDiff += abs(values[i] - values[i+1])
    meanDiff /= float(len(differences))
    print "Number of elements:",len(differences)
    for i in differences:
        stDev += (i - meanDiff)**2
    stDev /= float(len(differences))
    stDev = (stDev ** 0.5)
    print "mean: ",meanDiff," stDev: ",stDev
    return meanDiff,stDev

inp = input()
values = [x[1] for x in inp]
ranges = []
numIter,multiplier = 5,2
meanDiff,stDev,cur=float("inf"),float("inf"),-1
for i in range(numIter):
    if meanDiff <= stDev:
        meanDiff,stDev=getStats(values, meanDiff, stDev)
    else:
        pass
for i in range(len(values) - 1):
    diff = values[i] - values[i+1]
    if abs(diff) > (meanDiff+multiplier*stDev):
        if cur != -1:
            ranges.append((cur, inp[i+1][0] if diff < 0 else inp[i][0]))
            cur = -1
        else:
            cur = inp[i+1][0] if diff < 0 else inp[i][0]

sumX,sumY,sumXs,sumXY=0,0,0,0
for t in inp:
    sumX += t[0]
    sumY += t[1]
    sumXs += t[0]**2
    sumXY += (t[0]*t[1])
a = ((sumY*sumXs) - (sumX*sumXY))/float((len(inp)*sumXs)-(sumX**2))
b = ((sumXY) - (len(inp)*(sumX/float(len(inp)))*(sumY/float(len(inp)))))/(sumXs - (len(inp)*(sumX)))
print a,"+",b,"x"
#for i in ranges:
#    print "(",i[0],",",i[1],") ",values[i[0]]," ",values[i[1]]
print ranges