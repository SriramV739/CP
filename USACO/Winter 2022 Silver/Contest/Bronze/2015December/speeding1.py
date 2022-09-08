fin=open("speeding.in")
fout=open("speeding.out","w")
arr=[0]*100
curr=0
line=fin.readline().strip().split()
for i in range(int(line[0])):
    a=list(int(x) for x in fin.readline().strip().split())
    for j in range(curr,curr+a[0]):
        arr[j]=a[1]
    curr+=a[0]

curr=0
count=0
for j in range(int(line[1])):
    a=list(int(x) for x in fin.readline().strip().split())
    for i in range(curr,curr+a[0]):
        count=max(count,0,a[1]-arr[i])
    curr+=a[0]

fout.write(str(count))