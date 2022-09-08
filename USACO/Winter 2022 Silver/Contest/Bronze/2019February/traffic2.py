fin=open("traffic.in")
fout=open("traffic.out","w")
arr=[]
for i in range(int(fin.readline().strip())):
    arr.append(fin.readline().strip().split())
    arr[-1][1]=int(arr[-1][1])
    arr[-1][2]=int(arr[-1][2])

start=[]
end=[]

for i in range(len(arr)):
    if arr[i][0]=="none":
        first=i
        break

for i in range(first,len(arr)):
    l=arr[i]
    if len(end)==0:
        end=l[1:]
    else:
        if l[0]=="none":
            end[0]=max(end[0],l[1])
            end[1]=min(end[1],l[2])
        elif l[0]=="on":
            end[0]+=l[1]
            end[1]+=l[2]
        else:
            end[0]-=l[2]
            end[1]-=l[1]

for i in range(len(arr)-1,-1,-1):
    if arr[i][0]=="none":
        last=i
        break

for i in range(last,-1,-1):
    l=arr[i]
    if len(start)==0:
        start=l[1:]
    else:
        if l[0]=="none":
            start[0]=max(start[0],l[1])
            start[1]=min(start[1],l[2])
        elif l[0]=="on":
            start[0]-=l[2]
            start[1]-=l[1]
        else:
            start[0]+=l[1]
            start[1]+=l[2]

print(end)
fout.write(str(max(start[0],0))+" "+str(max(start[1],0)))
fout.write("\n")
fout.write(str(max(end[0],0))+" "+str(max(end[1],0)))


