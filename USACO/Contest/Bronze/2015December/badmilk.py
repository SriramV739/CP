fin=open("badmilk.in")
fout=open("badmilk.out","w")
fline=list(int(x) for x in fin.readline().strip().split())
dict1={}
for i in range(fline[2]):
    line=list(int(x) for x in fin.readline().strip().split())
    if line[0] in dict1:
        dict1[line[0]].append(line[1:])
    else:
        dict1[line[0]]=[line[1:]]
for i in dict1:
    dict1[i].sort(key=lambda x: x[1])
print(dict1)
badmilk=[]
for i in range(fline[-1]):
    possible=[]
    line=list(int(x) for x in fin.readline().strip().split())
    for j in dict1[line[0]]:
        if j[-1]<line[-1]:
            possible.append(j[0])
        else:
            break
    if i==0:
        badmilk=possible
    else:
        badmilk=list(set.intersection(set(possible),set(badmilk)))
res=[]
for i in badmilk:
    count=0 
    for j in dict1:
        for a in dict1[j]:
            if a[0]==i:
                count+=1
                break
    res.append(count)
fout.write(str(max(res)))
fout.write("\n")
