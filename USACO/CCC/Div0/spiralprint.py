n=int(input())
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in input().strip().split()))
res=[]
curr=n
pos=[0,-1]
while curr>1:
    for i in range(curr):
        pos[1]+=1
        res.append(arr[pos[0]][pos[1]])
    for i in range(curr-1):
        pos[0]+=1
        res.append(arr[pos[0]][pos[1]])
    for i in range(curr-1):
        pos[1]-=1
        res.append(arr[pos[0]][pos[1]])
    for i in range(curr-2):
        pos[0]-=1
        res.append(arr[pos[0]][pos[1]])


    curr-=2

if curr==1:
    res.append(arr[pos[0]][pos[1]+1])

for i in range(len(res)):
    print(res[i])

