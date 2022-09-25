fin=open("socdist1.in","r")
fout=open("socdist1.out","w")
n=int(fin.readline())
s=fin.readline().strip()
if s.count("0")==n:
    fout.write(str(n-1))
else:
    first=True
    count=0
    arr=[]
    for i in range(len(s)):
        if s[i]=="1":
            if first:
                if count!=0:
                    arr.append(count+1)
                else:
                    arr.append(count)
            else:
                arr.append(count+1)
            first=False
            count=0
        else:
            if i==0:
                first=True
            count+=1
    if count==0:
        arr.append(0)
    else:
        arr.append(count+1)
    print(arr)

    val=max(arr)
    if arr[0]==val or arr[-1]==val:
        edge=True
    else:
        edge=False
    if edge:
        onecut=val-1
        twocut=(val-1)//2
    else:
        onecut=val//2
        twocut=val//3
    if edge:
        if arr[0]==val:
            arr[0]=onecut
        else:
            arr[-1]=onecut
    else:
        arr[arr.index(val)]=onecut
    if max(arr)>onecut:
        if arr.index(max(arr))==0:
            arr[0]-=1
        elif arr.index(max(arr))==len(arr)-1:
            arr[-1]-=1
        else:
            arr[arr.index(max(arr))]=arr[arr.index(max(arr))]//2
    else:
        arr[arr.index(max(arr))]=twocut
    res=[]
    res.append(min(arr))
    try:
        res.append(min(arr[1:]))
    except:
        pass
    try:
        res.append(min(arr[:-1]))
    except:
        pass
    try:
        res.append(min(arr[1:-1]))
    except:
        pass
    if len(res)==0:
        fout.write(1)
    else:
        fout.write(str(max(res)))
    print(onecut,twocut,edge,val)

fout.write("\n")
