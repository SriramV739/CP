n=int(input())
arr=[]
for i in range(n):
    arr.append(int(input()))

res=[]
for i in range(len(arr)):
    count=0
    for j in range(i,len(arr)):
        count+=arr[j]
        res.append(count)
    for j in range(0,i-1):
        count+=arr[j]
        res.append(count)

print(max(res))