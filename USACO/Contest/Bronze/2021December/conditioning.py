n=int(input().strip())
start=list(int(x) for x in input().strip().split())
end=list(int(x) for x in input().strip().split())
arr=[]
for i in range(len(start)):
    arr.append(start[i]-end[i])

groups=[[]]
if arr[0]>=0:
    curr=1
else:
    curr=-1
for i in arr:
    if i>=0:
        if curr==1:
            groups[-1].append(i)
        else:
            groups.append([])
            groups[-1].append(i)
            curr=1
    else:
        if curr==-1:
            groups[-1].append(i)
        else:
            curr=-1
            groups.append([])
            groups[-1].append(i)

count=0

for a in range(len(groups)):
    val=groups[a]
    for i in range(len(val)):
        val[i]=abs(val[i])
        if i==0:
            count+=val[i]
            prev=val[i]
        else:
            if val[i]>prev:
                count+=(val[i]-val[i-1])
            prev=val[i]
print(count)