fin=open("balancing.in")
fout=open("balancing.out","w")
fline=list(int(x) for x in fin.readline().strip().split())
n=fline[0]
b=fline[1]
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))

def update(arr,xptr,yptr):
    quadrant=[0,0,0,0]
    for a in arr:
            if a[0]>xptr and a[1]>yptr:
                quadrant[0]+=1
            elif a[0]>xptr and a[1]<yptr:
                quadrant[1]+=1
            elif a[0]<xptr and a[1]>yptr:
                quadrant[2]+=1
            else:
                quadrant[3]+=1
    return(quadrant)
xarr=sorted(arr,key=lambda x: x[0])
yarr=sorted(arr,key=lambda x: x[0])
res=[]
for i in xarr:
    xptr=i[0]-1
    for j in yarr:
        yptr=j[1]-1
        quadrant=update(arr,xptr,yptr)
        res.append(max(quadrant))
    res.append(max(update(arr,xptr,yarr[-1][1]+1)))

xptr=xarr[-1][1]+1
for j in yarr:
    yptr=j[1]-1
    quadrant=update(arr,xptr,yptr)
    res.append(max(quadrant))
res.append(max(update(arr,xptr,yarr[-1][1]+1)))



fout.write(str(min(res)))
fout.write("\n")

