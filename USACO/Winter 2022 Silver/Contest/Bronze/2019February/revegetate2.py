n,m=map(int,input().strip().split())
dict1={}
for i in range(m):
    x,y=map(int,input().strip().split())
    if x in dict1:
        dict1[x].append(y)
    else:
        dict1[x]=[y]
    if y in dict1:
        dict1[y].append(x)
    else:
        dict1[y]=[x]

res=""
for i in range(1,n+1):
    if i in dict1:
        arr=dict1[i]
        arr=list(int(res[x-1]) for x in arr if x<i)
        for j in range(1,5):
            if j not in arr:
                res+=str(j)
                break
    else:
        res+="1"
print(res)