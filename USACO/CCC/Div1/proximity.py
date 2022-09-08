line=input().strip().split()
n=int(line[0])
k=int(line[1])
res=[]
dict1={}
for i in range(n):
    s=int(input().strip())
    if s in dict1:
        if i-dict1[s]<=k:
            res.append(s)
    dict1[s]=i

print(max(res))