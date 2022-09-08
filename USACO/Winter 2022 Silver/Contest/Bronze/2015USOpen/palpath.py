import itertools
fin=open("palpath.in")
fout=open("palpath.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    line=fin.readline().strip()
    arr.append([])
    for j in line:
        arr[-1].append(j)
res=[]
comb=list(x for x in range(2*(n-1)))
for i in list(itertools.combinations(comb,(n-1))):
    s=list("d" for x in range(2*(n-1)))
    i=list(i)
    for j in i:
        s[j]="r"
    check=""
    (a,b)=(0,0)
    for x in s:
        check+=(arr[a][b])
        if x=="r":
            b+=1
        else:
            a+=1
    check+=arr[a][b]
    res.append(check)
res=list(x for x in res if x[::-1]==x)
fout.write(str(len(list(set(res)))))
fout.write("\n")