fin=open("cownomics.in","r")
fout=open("cownomics.out","w")
fline=fin.readline()
fline=fline.split()
n=int(fline[0])
m=int(fline[1])
line=[]
for i in range(2*n):
    s=fin.readline()
    s=s.strip()
    line.append(s)
res=0
for i in range(m):
    test=True
    dict1={}
    for j in range(2*n):
        if j<=n-1:
            if line[j][i] in dict1:
                dict1[line[j][i]]+=1
            else:
                dict1[line[j][i]]=1
        else:
            if line[j][i] in dict1:
                test=False
                break
    if test:
        res+=1
fout.write(str(res))
fout.write("\n")