fin=open("measurement.in","r")
fout=open("measurement.out","w")
n=int(fin.readline().strip())
c=['Bessie','Elsie','Mildred']
m=[7,7,7]
arr=[]
for i in range(n):
    s=fin.readline().strip().split()
    s[0]=int(s[0])
    if s[-1][0]=="+":
        s[-1]=int(s[-1][1:])
    else:
        s[-1]=-(int(s[-1][1:]))
    arr.append(s)
arr.sort(key=lambda x: x[0])


def maxnum(arr):
    count=0
    maxarr=max(arr)
    for i in arr:
        if i==maxarr:
            count+=1
    return(count)
res=0
for i in arr:
    most=m.index(max(m))
    maxcount=maxnum(m)
    m[c.index(i[1])]+=i[2]
    if c[most]!=c[m.index(max(m))] or maxcount!=maxnum(m):
        res+=1

fout.write(str(res))
fout.write("\n")