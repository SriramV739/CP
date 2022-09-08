fin=open("cowroute.in")
fout=open("cowroute.out","w")
a,b,n=map(int,fin.readline().strip().split())
res=[]
for i in range(n):
    fline=list(int(x) for x in fin.readline().strip().split())
    sline=list(int(x) for x in fin.readline().strip().split())
    if a in sline and b in sline:
        if sline.index(a)<sline.index(b):
            res.append(fline[0])

if len(res)==0:
    fout.write("-1")
else:
    fout.write(str(min(res)))
fout.write("\n")