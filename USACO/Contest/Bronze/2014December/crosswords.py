fin=open("crosswords.in")
fout=open("crosswords.out","w")
n=list(int(x) for x in fin.readline().strip().split())
arr=[]
for i in range(n[0]):
    line=fin.readline().strip()
    arr.append([])
    for i in line:
        if i==".":
            arr[-1].append(True)
        else:
            arr[-1].append(False)
res=[]
for i in range(len(arr)):
     for j in range(len(arr[i])):
         test=True
         if arr[i][j]:
             #check horizontal
             if j==0 or not arr[i][j-1]:
                 if j<len(arr[i])-2 and arr[i][j+1] and arr[i][j+2]:
                     test=False
                     res.append(str(i+1)+" "+str(j+1))
             if test:
                if i==0 or not arr[i-1][j]:
                   if i<len(arr)-2 and arr[i+1][j] and arr[i+2][j]:
                       test=False
                       res.append(str(i+1)+" "+str(j+1))

fout.write(str(len(res)))
fout.write("\n")
for i in res:
    fout.write(i)
    fout.write("\n")