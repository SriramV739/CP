fin=open("badmilk.in")
fout=open("badmilk.out","w")
fline=list(int(x) for x in fin.readline().strip().split())
(n,m,d,s)=(fline[0],fline[0],fline[2],fline[3])
dict1={}
for i in range(d):
    line=list(int(x) for x in fin.readline().strip().split())
    if line[1] in dict1:
        dict1[line[1]][line[0]]=line[2]
    else:
        dict1[line[1]]={}
        dict1[line[1]][line[0]]=line[2]

sick={}
for i in range(s):
    line=list(int(x) for x in fin.readline().strip().split())
    sick[line[0]]=line[1]

res=[]

for i in dict1:
    test=True
    for j in sick:
        if j not in dict1[i]:
            test=False
            break
        else:
            if dict1[i][j]>=sick[j]:
                test=False
                break
    
    if test:
        res.append(len(dict1[i]))     

fout.write(str(max(res)))
fout.write("\n")