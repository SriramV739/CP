fin=open("crossings.in")
fout=open("crossings.out","w")
arr=[]
for i in range(int(fin.readline().strip())):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
arr1=sorted(arr, key=lambda x: x[0])

count=0
b=-1000000000000
dict1={}
for i in range(len(arr1)):
    if b<arr1[i][1]:
        dict1[str(arr1[i])]=True
    else:
        dict1[str(arr1[i])]=False
    b=max(b,arr1[i][1])
b=100000000000000000
for i in range(len(arr1)-1,-1,-1):
    if b<=arr1[i][1]:
        dict1[str(arr1[i])]=False
    b=min(b,arr1[i][1])


for i in dict1:
    if dict1[i]:
        count+=1

fout.write(str(count))
fout.write("\n")