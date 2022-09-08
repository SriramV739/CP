fin=open("breedflip.in","r")
fout=open("breedflip.out","w")
n=int(fin.readline().strip())
fline=fin.readline().strip()
sline=fin.readline().strip()
a=[]
b=[]
for i in range(n):
    a.append(fline[i])
    b.append(sline[i])
res=0
count=0
for i in range(n):
    if a[i]!=b[i]:
        count+=1
    else:
        if count!=0:
            res+=1
            count=0
fout.write(str(res))
fout.write("\n")
