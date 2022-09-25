fin=open("factory.in","r")
fout=open("factory.out","w")
n=int(fin.readline())
walkway=[]
for i in range(n-1):
    s=fin.readline()
    s=s.split()
    walkway.append([int(s[0]),int(s[1])])
print(walkway)
dict1={}
for i in walkway:
    if i[1] not in dict1:
        dict1[i[1]]=[i[0]]
    else:
        dict1[i[1]].append(i[0])
print(dict1)
test=[]
for i in range(1,n+1):
    test.append(i)
print(test)
res=[]
for i in dict1:
    if sorted(dict1[i]+[i])==test:
        res.append(i)
if len(res)!=0:
    fout.write(str(min(res)))
else:
    fout.write(str(-1))
fout.write("\n")
