fin=open("socdist1.in")
fout=open("socdist1.out","w")
n=int(fin.readline().strip())
arr=[]
s=fin.readline().strip()
for i in range(n):
    arr.append(int(s[i]))


corners=[]
regular=[]
if arr.count(1)==0:
    fout.write(str(len(arr)-1))
    fout.write("\n")
else:
    corners.append(arr.index(1))
    corners.append(list(reversed(arr)).index(1))
    test=False
    count=0
    for i in range(arr.index(1),len(arr)):
        if arr[i]==0:
            count+=1
            test=True
        if test and arr[i]==1:
            regular.append(count)
            count=0

    print(regular,corners)
    res=[]
    if len(regular)>0:
        res.append((max(regular)-2)//3+1)
    if len(regular)>1:
        res.append(min((max(regular)-1)//2,(sorted(regular)[-2]-1)//2)+1)

    for i in corners:
        if i!=0 and len(regular)>0:
            res.append(min(i-1,(max(regular)-1)//2)+1)
        if i>1:
            res.append((i-2)//2+1)

    if corners[0]!=0 and corners[1]!=0:
        res.append(min(corners[0],corners[1]))
    if len(res)==0:
        fout.write("1")


    else:
        for i in range(len(regular)):
            regular[i]+=1
        fout.write(str(min([max(res)]+regular)))

    fout.write("\n")