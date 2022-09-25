fin=open("factory.in","r")
fout=open("factory.out","w")
n=int(fin.readline())
walkway=[]
for i in range(n-1):
    s=fin.readline()
    s=s.split()
    walkway.append([int(s[0]),int(s[1])])
test=[]
for i in range(1,n+1):
    test.append(i)
test1=[]
count=0
res=True
for i in walkway:
    if count==0:
        count=i[1]
    else:
        if i[1]!=count:
            res=False
            break
    test1.append(i[0])
print(test1)
if res and sorted(test1+[count])==test:
    fout.write(str(count))
else:
    fout.write(str(-1))