fin=open("factory.in")
fout=open("factory.out","w")
n=int(fin.readline().strip())
arr=[]
for j in range(n-1):
    arr.append(list(int(x) for x in fin.readline().strip().split()))


for i in range(1,n+1):
    arr1=arr.copy()
    verified=[i]
    test=True
    add=[]
    while True:
        count=0
        for j in arr1:
            if j[1] in verified:
                add.append(j[0])
                count+=1
        arr1=list(x for x in arr1 if x[1] not in verified)
        verified+=add
        if count==0:
            break
        if len(arr1)==0:
            break
    if len(arr1)==0:
        fout.write(str(i))
        fout.write("\n")
        break
    if i==n:
        fout.write("-1")
        fout.write("\n")