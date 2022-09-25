fin=open("marathon.in")
fout=open("marathon.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))

total=0
for i in range(len(arr)-1):
    total+=(abs(arr[i][0]-arr[i+1][0])+abs(arr[i][1]-arr[i+1][1]))

x=0
for i in range(1,len(arr)-1):
    x=min(x,(abs(arr[i+1][0]-arr[i-1][0])+abs(arr[i+1][1]-arr[i-1][1])-abs(arr[i][0]-arr[i-1][0])-abs(arr[i][1]-arr[i-1][1])-abs(arr[i][0]-arr[i+1][0])-abs(arr[i][1]-arr[i+1][1])))

print(total)


fout.write(str(total+x))
fout.write("\n")
