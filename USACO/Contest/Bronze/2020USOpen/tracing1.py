fin=open("tracing.in")
fout=open("tracing.out","w")
line=fin.readline().strip().split()
s=fin.readline().strip()
print(s)
sick=[]
for i in s:
    if i=="0":
        sick.append(False)
    else:
        sick.append(True)
    
print(sick)

arr=[]

for i in range(int(line[1])):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
arr.sort(key=lambda x: x[0])

poss=[]
kmin=250
kmax=0

for k in range(0,int(line[1])+1):
    for i in range(int(line[0])):
        res=[]
        for j in range(int(line[0])):
            res.append([False,0])
        res[i][0]=True
        for a in arr:
            x=res[a[1]-1]
            y=res[a[2]-1]
            if x[0] and not y[0]:
                if x[1]<k:
                    res[a[2]-1][0]=True
                    res[a[1]-1][1]+=1
            elif y[0] and not x[0]:
                if y[1]<k:
                    res[a[1]-1][0]=True
                    res[a[2]-1][1]+=1
            elif y[0] and x[0]:
                res[a[1]-1][1]+=1
                res[a[2]-1][1]+=1
        final=list(x[0] for x in res)
        #print(final)
        if final==sick:
            poss.append(i)
            if k<kmin:
                kmin=k
            if k>kmax:
                kmax=k
if kmax==int(line[1]):
    kmax="Infinity"

fout.write(str(len(list(set(poss))))+" "+ str(kmin)+" "+str(kmax))
fout.write("\n")
            