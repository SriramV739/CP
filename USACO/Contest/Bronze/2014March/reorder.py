fin=open("reorder.in")
fout=open("reorder.out","w")
arr=[]
dest=[]
n=int(fin.readline().strip())
for i in range(n):
    arr.append(int(fin.readline().strip()))
for i in range(n):
    dest.append(int(fin.readline().strip()))

res=[]
while arr!=dest:
    for i in range(len(arr)):
        if arr[i]!=dest[i]:
            count=[]
            out=arr[i]
            arr[i]=-1
            while True:
                count.append(out)
                index=dest.index(out)
                out1=arr[index]
                arr[index]=out
                out=out1
                if out==-1:
                    break
            res.append(count)
            break


if len(res)==0:
    fout.write("-1")
else:
    x=max(res,key=lambda x:len(x))
    fout.write(str(len(res))+" "+str(len(x)))
fout.write("\n")
