fin=open("lazy.in")
fout=open("lazy.out","w")
n,k=map(int,fin.readline().strip().split())
arr=[]
dict1={}
for i in range(n):
    line=list(int(x) for x in fin.readline().strip().split())
    arr.append(line)
    dict1[line[1]]=line[0]
start=min(arr,key=lambda x: x[1])[1]
end=max(arr,key=lambda x: x[1])[1]
res={}
for i in range(start,end+1):
    if i==start:
        res[i]=0
        for j in list(dict1.keys()):
            if j-i<=k:
                res[i]+=dict1[j]
    else:
        res[i]=res[i-1]
        if i-k-1 in dict1:
            res[i]-=dict1[i-k-1]
        if i+k in dict1:
            res[i]+=dict1[i+k]

fout.write(str(max(list(res.values()))))
fout.write("\n")