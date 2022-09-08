n=int(input().strip())
if n==1:
    print(1)
else:
    arr=[]
    for i in range(n):
        arr.append(list(int(x) for x in input().strip().split()))

    arr.sort(key=lambda x: x[0]+x[1])

    arr1=[]
    for i in arr:
        arr1.append(i[1]-i[0])

    res=len(arr)
    maxcount=arr1[-1]
    for i in range(len(arr1)-1,-1,-1):
        if maxcount>arr1[i]:
            res-=1
        else:
            maxcount=arr1[i]

    print(res)