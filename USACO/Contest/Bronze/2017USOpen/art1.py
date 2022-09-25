fin=open("art.in")
fout=open("art.out","w")
arr=[]
colors=[]
for i in range(int(fin.readline().strip())):
    s=fin.readline().strip()
    arr.append([])
    for j in s:
        arr[-1].append(int(j))
        if int(j)!=0:
            colors.append(int(j))
colors=list(set(colors))
res=colors.copy()
for c in colors:
    for i in range(len(arr)):
        if c in arr[i]:
            top=i
            break
    for i in range(len(arr)-1,-1,-1):
        if c in arr[i]:
            down=i
            break
    for i in range(len(arr)):
        if c in list(arr[x][i] for x in range(len(arr))):
            left=i
            break
    for i in range(len(arr)-1,-1,-1):
        if c in list(arr[x][i] for x in range(len(arr))):
            right=i
            break
    for i in range(top,down+1):
        for j in range(left,right+1):
            if arr[i][j]!=c:
                if arr[i][j] in res:
                    res.remove(arr[i][j])
fout.write(str(len(res)))
fout.write("\n")