fin=open("cowroute.in")
fout=open("cowroute.out","w")
a,b,n=map(int,fin.readline().strip().split())
res=[]
trip=[]
arr=[]
to={}
fro={}
for i in range(n):
    fline=list(int(x) for x in fin.readline().strip().split())
    sline=list(int(x) for x in fin.readline().strip().split())
    if b in sline:
        for j in sline[:sline.index(b)]:
            if j in to:
                to[j]=min(to[j],fline[0])
            else:
                to[j]=fline[0]
    if a in sline:
        for j in sline[sline.index(a):]:
            if j!=a:
                if j in fro:
                    fro[j]=min(fro[j],fline[0])
                else:
                    fro[j]=fline[0]

if b in fro:
    res.append(fro[b])
for i in fro:
    if i in to:
        res.append(fro[i]+to[i])



if len(res)==0:
    fout.write("-1")
else:
    fout.write(str(min(res)))
fout.write("\n")