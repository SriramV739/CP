fin=open("hoofball.in")
fout=open("hoofball.out","w")
n=int(fin.readline().strip())
arr=sorted(list(int(x) for x in fin.readline().strip().split()))
passto=[]
for i in range(1000):
    passto.append(0)
def target(i,arr):
    if i==0:
        return(arr[i+1])
    elif i==len(arr)-1:
        return(arr[-2])
    else:
        if abs(arr[i]-arr[i-1])<=abs(arr[i+1]-arr[i]):
            return(arr[i-1])
        else:
            return(arr[i+1])
for i in range(n):
    passto[target(i,arr)]+=1
count=0
for i in range(n):
    if passto[arr[i]]==0:
        count+=1
    elif arr[i]<target(i,arr) and passto[arr[i]]==1 and passto[int(target(i,arr))]==1 and target(arr.index(target(i,arr)),arr)==arr[i]:
        count+=1

fout.write(str(count))
fout.write("\n")