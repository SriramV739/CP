fin=open("balancing.in")
fout=open("balancing.out","w")
def dist(x,y,arr):
    res=[0,0,0,0]
    for i in arr:
        if i[0]>x and i[1]>y:
            res[0]+=1
        elif i[0]<x and i[1]>y:
            res[1]+=1
        elif i[0]<x and i[1]<y:
            res[2]+=1
        else:
            res[3]+=1
    return(max(res))

n=int(fin.readline().strip().split()[0])
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))

arr1=sorted(arr,key=lambda x: x[0])
arr2=sorted(arr,key=lambda x: x[1])
final=[]
final.append(dist(0,0,arr))
first=True
for i in arr1:
    if first:
        x=0
        first=False
    else:
        x=i[0]+1
    for j in arr2:
        final.append(dist(x,j[1]+1,arr))

fout.write(str(min(final)))
fout.write("\n")
