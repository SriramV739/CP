fin=open("mowing.in")
fout=open("mowing.out","w")
n=int(fin.readline().strip())
pos=[0,0]
time=0
res=[]
dict1={"[0,0]":0}
for j in range(n):
    arr=fin.readline().strip().split()
    arr[1]=int(arr[1])
    for i in range(arr[1]):
        if arr[0]=="N":
            pos[1]+=1
        elif arr[0]=="S":
            pos[1]-=1
        elif arr[0]=="E":
            pos[0]+=1
        else:
            pos[0]-=1
        time+=1
        if str(pos) in dict1:
            res.append(time-dict1[str(pos)])
            dict1[str(pos)]=time
            for i in list(dict1.keys())[:list(dict1.keys()).index(str(pos))]:
                del dict1[i]
        else:
            dict1[str(pos)]=time
print(res)
if len(res)==0:
    fout.write("-1")
else:
    fout.write(str(min(res)))
fout.write("\n")