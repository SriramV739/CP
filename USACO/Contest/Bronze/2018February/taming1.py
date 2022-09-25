fin=open("taming.in")
fout=open("taming.out","w")
n=int(fin.readline().strip())
arr=list(int(x) for x in fin.readline().strip().split())
arr[0]=0

for i in range(len(arr)):
    if arr[i]!=-1:
        count=arr[i]-1
        test=False
        for j in range(i-1,i-arr[i]-1,-1):
            if arr[j]==-1:
                arr[j]=count
            elif arr[j]!=count:
                test=True
                break
            count-=1
                

        if test:
            fout.write("-1")
            break
print(arr)
if not test:
    fout.write(str(arr.count(0))+" "+str(arr.count(0)+arr.count(-1)))
fout.write("\n")
