fin=open("mirror.in")
fout=open("mirror.out","w")
n,m=map(int,fin.readline().strip().split())
arr=[]
for i in range(n):
    arr.append(list(i for i in fin.readline().strip()))

def traverse(dir,arr,enter):
    curr=enter.copy()
    count=0
    while True:
        pos=arr[curr[0]][curr[1]]
        if dir=="s":
            if pos=="/":
                curr[1]-=1
                dir="w"
            else:
                curr[1]+=1
                dir="e"
        elif dir=="n":
            if pos=="/":
                curr[1]+=1
                dir="e"
            else:
                curr[1]-=1
                dir="w"
        elif dir=="e":
            if pos=="/":
                curr[0]-=1
                dir="n"
            else:
                curr[0]+=1
                dir="s"
        else:
            if pos=="/":
                curr[0]+=1
                dir="s"
            else:
                curr[0]-=1
                dir="n"
        count+=1
        if curr[0]>=n or curr[1]>=m or curr[0]<0 or curr[1]<0:
            break
    return(count)
res=[]
for i in range(len(arr)):
    res.append(traverse("e",arr,[i,0]))
    res.append((traverse("w",arr,[i,m-1])))

for j in range(m):
    res.append((traverse("s",arr,[0,j])))
    res.append((traverse("n",arr,[n-1,j])))



fout.write(str(max(res)))
fout.write("\n")