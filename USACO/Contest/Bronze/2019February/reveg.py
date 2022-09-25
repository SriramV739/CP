fin=open("revegetate.in")
fout=open("revegetate.out","w")
line=list(int(x) for x in fin.readline().strip().split())
numcow=line[0]
pasture=line[1]
dict1={}
for i in range(1,pasture+1):
    dict1[i]=[]

for i in range(numcow):
    line=list(int(x) for x in fin.readline().strip().split())
    dict1[line[0]].append(line[1])
    dict1[line[1]].append(line[0])

arr=[]
for i in sorted(list(dict1.keys())):
    max1=0
    for j in dict1[i]:
        if j<i:
            if arr[j-1]>max1:
                max1=arr[j-1]
    arr.append(max1+1)
