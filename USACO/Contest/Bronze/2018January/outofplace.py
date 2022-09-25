fin=open("outofplace.in")
fout=open("outofplace.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    arr.append(int(fin.readline().strip()))

def retind(arr,element):
    res=[]
    for i in range(len(arr)):
        if arr[i]==element:
            res.append(i)
    return(res)

arr1=sorted(arr)
val=[]
for i in range(n):
    if arr[i]!=arr1[i]:
        val.append(arr[i])
        val.append(arr1[i])
        break

if len(val)==0:
    fout.write("0")
    fout.write("\n")
else:

    for i in val:
        indices=retind(arr,i)
        for j in indices:
            arr2=arr.copy()
            del arr2[j]
            if arr2==sorted(arr2):
                index=j
                break


    if index==0:
        index1=index
        arr=[arr[index]]+sorted(list(set(arr[index+1:])))
    elif index==n-1:
        index1=len(list(set(arr)))-1
        arr=sorted(list(set(arr[:index])))+[arr[index]]
    else:
        index1=len(list(set(arr[:index])))
        arr=sorted(list(set(arr[:index])))+[arr[index]]+sorted(list(set(arr[index+1:])))
    arr1=sorted(arr)
    print(index)
    fout.write(str(min(abs(arr1.index(arr[index1])-index1),abs(arr1[::-1].index(arr[index1])-(len(arr)-1-index1)))))
    fout.write("\n")