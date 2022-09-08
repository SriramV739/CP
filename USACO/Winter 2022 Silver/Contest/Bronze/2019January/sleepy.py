fin=open("sleepy.in")
fout=open("sleepy.out","w")
n=int(fin.readline().strip())
arr=list(int(x) for x in fin.readline().strip().split())

def findelement(element,arr):
    last=0
    for i in range(len(arr)):
        for j in range(i,len(arr)):
            if arr[j]<arr[i]:
                last=i
                break
    res=last
    for i in range(last,len(arr)):
        if element>arr[i]:
            res=i
    return(res)

count=0
while sorted(arr)!=arr:
    first=arr[0]
    arr.insert(findelement(first,arr),arr.pop(0))
    count+=1


fout.write(str(count))
fout.write("\n")