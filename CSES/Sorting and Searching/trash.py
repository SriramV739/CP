firstLine=input().strip().split()
n=int(firstLine[0])
arr=[]
arr1=[]
dict1={}
for i in range(n):
    firstLine=input().strip().split()
    arr.append(int(firstLine[0]))
    arr.append(int(firstLine[1]))
    dict1[int(firstLine[0])]=1
    dict1[int(firstLine[1])]=-1
counter=0
res=0
arr.sort()
for i in range(len(arr)):
    counter+=dict1[arr[i]]
    res=max(res,counter)
print(res)