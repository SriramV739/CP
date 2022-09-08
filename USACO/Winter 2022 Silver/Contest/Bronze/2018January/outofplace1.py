fin=open("outofplace.in")
fout=open("outofplace.out","w")
arr=[]
for i in range(int(fin.readline().strip())):
    arr.append(int(fin.readline().strip()))
arr1=sorted(arr.copy())
if arr1==arr:
    fout.write("0")
    fout.write("\n")
else:
    for i in range(len(arr)):
        if arr1[i]!=arr[i]:
            test=True
            if i!=0:
                if arr[i]<arr[i-1]:
                    test=False
            if i!=len(arr)-1:
                if arr[i]>arr[i+1]:
                    test=False
            if test:
                val=arr1[i]
            else:
                val=arr[i]
            break
    print(val)
    up=True
    for i in range(len(arr)):
        if arr[i]==val:
            if i!=0:
                if arr[i]<arr[i-1]:
                    index=i
                    break
            if i!=len(arr)-1:
                if arr[i]>arr[i+1]:
                    up=False
                    index=i
                    break


                

    def orderdup(arr):
        dict1={}
        arr2=[]
        for i in arr:
            if i not in dict1:
                arr2.append(i)
                dict1[i]=1
        return(arr2)
    arr=list(arr[x] for x in range(len(arr)) if x==index or arr[x]!=val)
    arr=orderdup(arr)
    arr1=list(set(arr1))
    print(arr1)
    fout.write(str(abs(sorted(arr).index(val)-arr.index(val))))
    fout.write("\n")

'''
dict1={}



count=0
i=index
print(i)
if up:
    while True:
        if arr[i]<arr[i-1]:
            (arr[i],arr[i-1])=(arr[i-1],arr[i])
            if arr[i] not in dict1:
                dict1[arr[i]]=1
                count+=1
        else:
            break
        i-=1
else:
    while True:
        if arr[i]>arr[i+1]:
            (arr[i],arr[i+1])=(arr[i+1],arr[i])
            if arr[i] not in dict1:
                dict1[arr[i]]=1
                count+=1
        else:
            break
        i+=1
fout.write(str(count))
fout.write("\n")
'''