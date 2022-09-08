fin=open("backforth.in")
fout=open("backforth.out","w")
b1=[]
b2=[]
for i in fin.readline().strip().split():
    b1.append(int(i))
for i in fin.readline().strip().split():
    b2.append(int(i))

count=[0,0,0,0]
res=[]
for i in b1:
    count[0]=i
    tues=b2.copy()
    tues.append(i)
    for j in tues:
        wed=b1.copy()
        wed.remove(i)
        wed.append(j)
        count[1]=j
        for a in wed:
            thurs=tues.copy()
            thurs.remove(j)
            thurs.append(a)
            count[2]=a
            for b in thurs:
                count[3]=b
                res.append(-count[0]+count[1]-count[2]+count[3])
            
fout.write(str(len(list(set(res)))))
fout.write("\n")
