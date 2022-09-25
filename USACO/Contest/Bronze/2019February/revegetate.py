fin=open("revegetate.in")
fout=open("revegetate.out","w")
line=list(int(x) for x in fin.readline().strip().split())
dict1={}
for i in range(1,line[0]+1):
    dict1[i]=[]


for i in range(line[1]):
    line1=list(int(x) for x in fin.readline().strip().split())
    dict1[line1[0]].append(line1[1])
    dict1[line1[1]].append(line1[0])
print(dict1)

arr=[]
for i in dict1:
    l=[]
    for j in dict1[i]:
        if j<i:
            l.append(arr[j-1])
    l=list(set(l))
    a=1
    for a in range(1,5):
        if a not in l:
            break
    arr.append(a)
res=""
for i in arr:
    res+=str(i)
print(res)
fout.write(res)
fout.write("\n")