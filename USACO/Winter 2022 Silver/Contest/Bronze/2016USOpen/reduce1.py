fin=open("reduce.in")
fout=open("reduce.out","w")
arr=[]
n=int(fin.readline().strip())
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))

def compute(arr):
    (minx,miny,maxx,maxy)=([40000,40000],[40000,40000],[0,0],[0,0])

    for i in arr:
        if i[0]<minx[0]:
            minx=i
        if i[1]<miny[1]:
            miny=i
        if i[0]>maxx[0]:
            maxx=i
        if i[1]>maxy[1]:
            maxy=i
    return([minx,miny,maxx,maxy])

res=[]

rem=compute(arr)
for i in rem:
    arr1=[]
    for j in arr:
        if j!=i:
            arr1.append(j)
    area=compute(arr1)
    print(area)
    res.append((area[2][0]-area[0][0])*(area[3][1]-area[1][1]))

fout.write(str(min(res)))
fout.write("\n")