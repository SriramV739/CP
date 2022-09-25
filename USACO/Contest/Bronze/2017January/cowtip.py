from sys import implementation


fin=open("cowtip.in")
fout=open("cowtip.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    s=fin.readline().strip()
    arr.append([])
    for j in s:
        if j=="0":
            arr[-1].append(True)
        else:
            arr[-1].append(False)

def zerocheck(arr):
    for i in arr:
        for j in i:
            if not j:
                return(True)
    return(False)


def update(x,y,arr):
    for i in range(y+1):
        for j in range(x+1):
            arr[i][j]=not(arr[i][j])

count=0

while zerocheck(arr):
    print(arr)
    i=0
    j=0
    for i in range(n-1,-1,-1):
        if False in arr[i]:
            for j in range(n-1,-1,-1):
                if not arr[i][j]:
                    count+=1
                    update(j,i,arr)
                    break
            break
    print(i,j)
    print(arr)
    

fout.write(str(count))
fout.write("\n")
