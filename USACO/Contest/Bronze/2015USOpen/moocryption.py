fin=open("moocrypt.in")
fout=open("moocrypt.out","w")
a,b=map(int,fin.readline().strip().split())
arr=[]
for i in range(a):
    s=fin.readline().strip()
    arr.append([])
    for j in s:
        arr[-1].append(j)

char="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
res=[0]
for m in char:
    for o in char:
        if m!=o:
            count=0
            for i in range(len(arr)):
                for j in range(len(arr[i])):
                    if arr[i][j]==m:
                        if 2<=i:
                            if arr[i-1][j]==o and arr[i-2][j]==o:
                                count+=1
                        if i<=len(arr)-3:
                            if arr[i+1][j]==o and arr[i+2][j]==o:
                                count+=1
                        if j>=2:
                            if arr[i][j-1]==o and arr[i][j-2]==o:
                                count+=1
                        if j<=len(arr[i])-3:
                            if arr[i][j+1]==o and arr[i][j+2]==o:
                                count+=1
                        if i>=2 and j>=2:
                            if arr[i-1][j-1]==o and arr[i-2][j-2]==o:
                                count+=1
                        if i>=2 and j<=len(arr[i])-3:
                            if arr[i-1][j+1]==o and arr[i-2][j+2]==o:
                                count+=1
                        if i<=len(arr)-3 and j>=2:
                            if arr[i+1][j-1]==o and arr[i+2][j-2]==o:
                                count+=1
                        if i<=len(arr)-3 and j<=len(arr[i])-3:
                            if arr[i+1][j+1]==o and arr[i+2][j+2]==o:
                                count+=1

            res.append(count)
fout.write(str(max(res)))
fout.write("\n")
