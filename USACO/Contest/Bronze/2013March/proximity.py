fin=open("proximity.in")
fout=open("proximity.out","w")
n,k=map(int,fin.readline().strip().split())
dict1={}
res=[]
for i in range(n):
    x=int(fin.readline().strip())
    if x in dict1:
        if i-dict1[x]<=k:
            res.append(x)
    dict1[x]=i

fout.write(str(max(res)))
fout.write("\n")