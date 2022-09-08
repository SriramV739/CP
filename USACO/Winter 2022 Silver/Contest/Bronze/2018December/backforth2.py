fin=open("backforth.in")
fout=open("backforth.out","w")
barn1=list(int(x) for x in fin.readline().strip().split())
barn2=list(int(x) for x in fin.readline().strip().split())
used=[0,0,0,0]
def oppsum(arr):
    pos=False
    count=0
    for i in arr:
        if pos:
            pos=False
            count+=i
        else:
            pos=True
            count-=i
    return(count)
res=[]
for i in list(set(barn1)):
    tues=barn2+[i]
    used[0]=i
    for j in list(set(tues)):
        wed=barn1.copy()
        wed.remove(i)
        wed.append(j)
        used[1]=j
        for a in list(set(wed)):
            thurs=tues.copy()
            thurs.remove(j)
            thurs.append(a)
            used[2]=a
            for b in list(set(thurs)):
                used[3]=b
                print(used)
                res.append(oppsum(used))


fout.write(str(len(list(set(res)))))
fout.write("\n")