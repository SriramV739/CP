fin=open("socdist2.in")
fout=open("socdist2.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    arr.append([(int(x)) for x in fin.readline().strip().split()])
    arr[-1][1]=bool(arr[-1][1])

arr.sort(key=lambda x: x[0])
r=1000000
for i in range(0,len(arr)-1):
    if arr[i][1] and not arr[i+1][1]:
        if r>arr[i+1][0]-arr[i][0]:
            r=arr[i+1][0]-arr[i][0]
    elif not arr[i][1] and arr[i+1][1]:
        if r>arr[i+1][0]-arr[i][0]:
            r=arr[i+1][0]-arr[i][0]

count=1
for i in range(0,len(arr)-1):
    a=arr[i]
    b=arr[i+1]
    if a[1] and b[1]:
        if b[0]-a[0]<r:
            a[1]=False
        else:
            count+=1
    elif not a[1] and b[1]:
        count+=1


fout.write(str(count))
fout.write("\n")
