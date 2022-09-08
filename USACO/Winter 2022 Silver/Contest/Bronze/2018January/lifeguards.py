fin=open("lifeguards.in")
fout=open("lifeguards.out","w")
n=int(fin.readline().strip())
arr=[]
time=[0]*1000
totalcount=0
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
    time[int(arr[-1][0]-1):int(arr[-1][1])-1]=[x+1 for x in time[int(arr[-1][0]-1):int(arr[-1][1])-1]]

print(time[:9])
for i in time:
    if i!=0:
        totalcount+=1

print(totalcount)

res=[]
for i in arr:
    count=0
    for j in range(i[0]-1,i[1]-1):
        if time[j]==1:
            count+=1
    res.append(totalcount-count)

print(res)
fout.write(str(max(res)))
fout.write("\n")


"""fin=open("lifeguards.in")
fout=open("lifeguards.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
res=[]
for i in arr:
    time=[False]*1000
    count=0
    for j in arr:
        if i!=j:
            for a in range(j[0]-1,j[1]-1):
                time[a]=True
    res.append(time.count(True))
fout.write(str(max(res)))
fout.write("\n")"""