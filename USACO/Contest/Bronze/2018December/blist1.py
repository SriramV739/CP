fin=open("blist.in")
fout=open("blist.out","w")
arr=[]
n=int(fin.readline().strip())
for i in range(n):
    a=list(int(x) for x in fin.readline().strip().split())
    arr.append([a[0],a[-1],"s"])
    arr.append([a[1],a[-1],"e"])

arr.sort(key=lambda x: x[0])
pile=0
res=0
for i in arr:
    if i[-1]=="s":
        res+=max(i[1]-pile,0)
        if i[1]<=pile:
            pile-=i[1]
        else:
            pile=0
    else:
        pile+=i[1]

fout.write(str(res))
    