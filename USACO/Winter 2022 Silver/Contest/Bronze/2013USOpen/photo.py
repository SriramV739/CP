fin=open("photo.in")
fout=open("photo.out","w")
n,k=map(int,fin.readline().strip().split())
res=0
arr=list(i for i in range(1,n+1))
dict1={}
for i in range(k):
    line=list(int(x) for x in fin.readline().strip().split())
    dict1[min(line)]=max(line)
curr=0
while True:
    val=(list(dict1[i] for i in list(dict1.keys()) if i>=arr[curr])).copy()
    if len(val)==0:
        res+=1
        break
    else:
        res+=1
        curr=min(val)
    if curr>=len(arr):
        res+=1
        break
fout.write(str(res))
fout.write("\n")
