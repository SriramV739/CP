fin=open("blink.in")
fout=open("blink.out","w")
n,b=map(int,fin.readline().strip().split())
arr=[]
for i in range(n):
    arr.append(int(fin.readline().strip()))
dict1={}
total=[]
count=0
while True:
    change=[]
    for i in range(len(arr)):
        if arr[i-1]==1:
            change.append(i)
    for j in change:
        arr[j]=abs(arr[j]-1)
    if str(arr.copy()) in dict1:
        count+=1
        repeat=arr.copy()
        break
    else:
        count+=1
        dict1[str(arr.copy())]=1
        total.append(arr.copy())


if len(total)>=b:
    curr=total[b-1]

else:
    b-=total.index(repeat)
    total=total[total.index(repeat):]
    curr=total[(b%len(total))-1]

for i in curr:
    fout.write(str(i))
    fout.write("\n")
