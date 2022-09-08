fin=open("mowing.in")
fout=open("mowing.out","w")
pos=[0,0]
dict1={str(pos[0])+" "+str(pos[1]):[0]}

time=0

for i in range(int(fin.readline().strip())):
    line=fin.readline().strip().split()
    for i in range(int(line[1])):
        time+=1
        if line[0]=="N":
                pos[1]+=1
                
        elif line[0]=="S":
                pos[1]-=1
                
        elif line[0]=="E":
                pos[0]+=1
                
        else:
                pos[0]-=1
                
        s=str(pos[0])+" "+str(pos[1])
        if s in dict1:
            dict1[s].append(time)
        else:
            dict1[s]=[time]
res=[]
for i in dict1:
    if len(dict1[i])>1:
        for j in range(len(dict1[i])-1):
            res.append(dict1[i][j+1]-dict1[i][j])

if len(res)==0:
    fout.write("-1")
else:
    fout.write(str(min(res)))
fout.write("\n")