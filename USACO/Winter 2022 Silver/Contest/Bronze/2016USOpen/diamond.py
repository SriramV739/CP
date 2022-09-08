fin=open("diamond.in")
fout=open("diamond.out","w")
line=list(int(x) for x in fin.readline().strip().split())
n=line[0]
k=line[1]
arr=[]
for i in range(n):
    arr.append(int(fin.readline().strip()))

arr.sort()
res=[]
for i in range(len(arr)):
    for j in range(len(arr)):
        if i!=j:
            if abs(arr[i]-arr[j])<=k:
                res.append(abs(i-j)+1)

fout.write(str(max(res)))
fout.write("\n")