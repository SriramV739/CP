fin=open("mixmilk.in","r")
fout=open("mixmilk.out","w")
arr=[]
for i in range(3):
    s=fin.readline().strip().split()
    for i in range(len(s)):
        s[i]=int(s[i])
    arr.append(s)
curr=0
for i in range(100):
    if curr==2:
        next=0
    else:
        next=curr+1
    if arr[curr][1]<=arr[next][0]-arr[next][1]:
        arr[next][1]+=arr[curr][1]
        arr[curr][1]=0
    else:
        arr[curr][1]-=arr[next][0]-arr[next][1]
        arr[next][1]=arr[next][0]
    curr=next

for i in arr:
    fout.write(str(i[1]))
    fout.write("\n")