fin=open("mowing.in")
fout=open("mowing.out","w")
n=int(fin.readline().strip())
pos=[0,0]
time=1
dict1={str([0,0]):1}
res=[]
for i in range(n):
    arr=fin.readline().strip().split()
    arr[1]=int(arr[1])
    add=[0,0]
    if arr[0]=="N":
        add=[1,1]
    elif arr[0]=="S":
        add=[1,-1]
    elif arr[0]=="E":
        add=[0,1]
    else:
        add=[0,-1]
    for j in range(arr[1]):
        time+=1
        pos[add[0]]+=add[1]
        if str(pos) in dict1:
                res.append(time-dict1[str(pos)])
                dict1[str(pos)]=time
        else:
            dict1[str(pos)]=time

if len(res)==0:
    fout.write("-1")
else:
    fout.write(str(min(res)))
fout.write("\n")
