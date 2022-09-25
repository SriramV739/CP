fin=open("speeding.in")
fout=open("speeding.out","w")
b=[]
arr=[]
f=fin.readline().strip().split()
for i in range(int(f[0])):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
for i in range(int(f[1])):
    b.append(list(int(x) for x in fin.readline().strip().split()))

(curr,res)=(0,0)
for i in b:
    dis=i[0]
    speed=i[1]
    while dis>0:
        if arr[curr][0]>dis:
            arr[curr][0]-=dis
            res=max(0,speed-arr[curr][1],res)
            dis=0
        else:
            dis=dis-arr[curr][0]
            res=max(0,speed-arr[curr][1],res)
            arr[curr][0]=0
            curr+=1
fout.write(str(res))
fout.write("\n")