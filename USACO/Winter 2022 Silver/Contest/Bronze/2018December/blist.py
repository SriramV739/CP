fin=open("blist.in","r")
fout=open("blist.out","w")
n=int(fin.readline().strip())   
arr=[]
for i in range(n):
    arr.append(fin.readline().strip().split())
    for j in range(len(arr[-1])):
        arr[-1][j]=int(arr[-1][j])
arr.sort(key=lambda x: x[0])
print(arr)
time=[]
res=0
for a in arr:
    print(a)
    start=a[0]
    end=a[1]
    bucket=a[-1]
    i=0
    test=True
    for i in range(min(bucket,len(time))):
        if time[i]>start:
            test=False
            break
    if test and len(time)!=0:
        if i==len(time)-1 or i==bucket-1:
            i+=1
    print(time,i,res)
    res+=(max(0,bucket-i))
    del time[:i]
    for j in range(bucket):
        time.append(end+1)
    time.sort()
    
fout.write(str(res))
fout.write("\n")
    







