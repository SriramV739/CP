fin=open("lazy.in")
fout=open("lazy.out","w")
n,k=map(int,fin.readline().strip().split())
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
arr.sort(key=lambda x:x[1])
start=0
end=0
p=[]
sum=0
for i in arr:
    sum+=i[0]
    p.append(sum)
res=[]
while True:
    if arr[end][1]-arr[start][1]<=(2*k):
        if start==0:
            res.append(p[end])
        else:
            res.append(p[end]-p[start-1])
    if arr[end][1]-arr[start][1]<=(2*k):
        end+=1
    else:
        start+=1
    if start>end:
        break
    if end==len(arr):
        break
    
    
fout.write(str(max(res)))
fout.write("\n")