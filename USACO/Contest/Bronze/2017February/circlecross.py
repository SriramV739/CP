fin=open("circlecross.in")
fout=open("circlecross.out","w")
s="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
line=[]
for i in (fin.readline().strip()):
    line.append(i)
res=0
for i in s:
    dict1={}
    for j in range(line.index(i)+1,len(line)):
        if line[j]==i:
            break
        else:
            if line[j] in dict1:
                dict1[line[j]]+=1
            else:
                dict1[line[j]]=1
    for i in list(dict1.keys()):
        if dict1[i]==1:
            res+=1
fout.write(str(res//2))
fout.write("\n")

