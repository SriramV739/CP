fin=open("cowjog.in")
fout=open("cowjog.out","w")
n=int(fin.readline().strip())
l=[]
for i in range(n):
    l.append(list(int(x) for x in fin.readline().strip().split()))
l.sort(key=lambda x: x[0])
arr=[]
for i in l:
    arr.append(i[1])
count=n
for i in range(len(arr)-1,0,-1):
    if arr[i]<arr[i-1]:
        arr[i-1]=arr[i]
        count-=1

fout.write(str(count))
fout.write("\n")   