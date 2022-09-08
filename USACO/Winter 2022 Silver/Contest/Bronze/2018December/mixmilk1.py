fin=open("mixmilk.in")
fout=open("mixmilk.out","w")
arr=[]
for i in range(3):
    arr.append(list(int(x) for x in fin.readline().strip().split()))

curr=0
next=1
for i in range(100):
    if arr[next][1]+arr[curr][1]>arr[next][0]:
        arr[curr][1]-=(arr[next][0]-arr[next][1])
        arr[next][1]=arr[next][0]
    else:
        arr[next][1]+=arr[curr][1]
        arr[curr][1]=0
    curr+=1
    next+=1
    if curr==3:
        curr=0
    if next==3:
        next=0

for i in arr:
    fout.write(str(i[1]))
    fout.write("\n")