import itertools
line=list(int(x) for x in input().strip().split())
m=line[0]
n=line[1]
arr=[]
for i in range(2*m):
    s=input().strip()
    arr.append([])
    for j in s:
        arr[-1].append(j)
res=0
for z in list(itertools.combinations(range(n),3)):
    z=list(z)
    i=z[0]
    j=z[1]
    k=z[2]
    dict1={}
    for a in range(m):
        b=arr[a][i]+arr[a][j]+arr[a][k]
        dict1[b]=True
    for a in range(m,2*m):
        b=arr[a][i]+arr[a][j]+arr[a][k]
        if b in dict1:
            break
        if a==2*m-1:
            res+=1

print(res)