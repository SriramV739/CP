fin=open("backforth.in")
fout=open("backforth.out","w")
fline=list(int(x) for x in fin.readline().strip().split())
sline=list(int(x) for x in fin.readline().strip().split())
barn1={}
barn2={}
for i in range(10):
    if fline[i] in barn1:
        barn1[fline[i]]+=1
    else:
        barn1[fline[i]]=1
    if sline[i] in barn2:
        barn2[sline[i]]+=1
    else:
        barn2[sline[i]]=1



def update(arr,barn1,barn2):
    dict1=barn1.copy()
    dict2=barn2.copy()
    test=True
    for i in arr:
        if test:
            test=False
            dict1[i]-=1
            if dict1[i]==0:
                del dict1[i]
            if i in dict2:
                dict2[i]+=1
            else:
                dict2[i]=1
        else:
            test=True
            dict2[i]-=1
            if dict2[i]==0:
                del dict2[i]
            if i in dict1:
                dict1[i]+=1
            else:
                dict1[i]=1
    return([list(dict1.keys()),list(dict2.keys())])

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

final=[]
res=[0,0,0,0]
for i in barn1:
    res[0]=i
    a=update(res[:1],barn1,barn2)[1]
    #print(a)
    for j in a:
        res[1]=j
        b=update(res[:2],barn1,barn2)[0]
        print(b,j,i)
        for k in b:
            res[2]=k
            c=update(res[:3],barn1,barn2)[1]
            for l in c:
                res[3]=l
                final.append(oppsum(res))

print(final)
fout.write(str(len(list(set(final)))))
fout.write("\n")