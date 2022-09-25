fin=open("taming.in")
fout=open("taming.out","w")
n=int(fin.readline().strip())
arr=list(int(x) for x in fin.readline().strip().split())
testbreak=False
arr[0]=0
for i in range(len(arr)):
    if testbreak:
        break
    if arr[i]!=-1:
        change=0
        for j in range(i-arr[i],i):
            if arr[j]!=-1 and arr[j]!=change:
                fout.write("-1")
                fout.write("\n")
                testbreak=True
                break
            arr[j]=change
            change+=1
if not testbreak:
    fout.write(str(arr.count(0))+" "+ str(arr.count(0)+arr.count(-1)))
    fout.write("\n")