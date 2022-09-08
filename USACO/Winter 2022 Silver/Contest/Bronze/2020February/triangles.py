fin=open("triangles.in","r")
fout=open("triangles.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    s=fin.readline().strip().split()
    for j in range(len(s)):
        s[j]=int(s[j])
    arr.append(s)
res=[]
for i in arr:
    (pv,ph,nv,nh)=(0,0,0,0)
    for j in arr:
        if i!=j:
            if j[0]==i[0]:
                if j[1]<i[1] and abs(j[1]-i[1])>nv:
                    nv=abs(j[1]-i[1])
                if j[1]>i[1] and abs(j[1]-i[1])>pv:
                    pv=abs(j[1]-i[1])
            if j[1]==i[1]:
                if j[0]<i[0] and abs(j[0]-i[0])>nh:
                    nh=abs(j[0]-i[0])
                if j[0]>i[0] and abs(j[0]-i[0])>ph:
                    ph=abs(j[0]-i[0])
    maxh=max(nh,ph)
    maxv=max(nv,pv)
    res.append(maxh*maxv)
fout.write(str(max(res)))
fout.write("\n")