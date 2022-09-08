fin=open("cowtip.in")
fout=open("cowtip.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    s=fin.readline().strip()
    arr.append([])
    for j in s:
        arr[-1].append(int(j))

def fullcheck(arr):
    for i in arr:
        for j in i:
            if j==1:
                return(False)
    return(True)

def reverse(arr,i,j):
    for x in range(i+1):
        for y in range(j+1):
            if arr[x][y]==0:
                arr[x][y]=1
            else:
                arr[x][y]=0


res=0
while not fullcheck(arr):
    i=0
    for i in range(len(arr)-1,-1,-1):
        if 1 in arr[i]:
            j=0
            for a in range(len(arr[i])):
                if arr[i][a]==1:
                    j=a
            break
    print(i,j)
    reverse(arr,i,j)
    res+=1

fout.write(str(res))
fout.write("\n")