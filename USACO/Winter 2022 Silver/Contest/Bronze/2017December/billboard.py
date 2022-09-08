fin=open("billboard.in","r")
fout=open("billboard.out","w")
arr=[]
for i in range(3):
    arr.append(fin.readline().strip().split())
    for j in range(len(arr[-1])):
        arr[-1][j]=int(arr[-1][j])



def intersection(arr1,arr2):
    if arr1[2]>arr2[2]:
        mx=arr1
        sx=arr2
    else:
        mx=arr2
        sx=arr1
    if arr1[3]>arr2[3]:
        my=arr1
        sy=arr2
    else:
        my=arr2
        sy=arr1
    if my[1]<sy[3] and mx[0]<sx[2]:
        s1=sy[3]-max(my[1],sy[1])
        s2=sx[2]-max(mx[0],sx[0])
        return(s1*s2)
    else:
        return(0)


def area(arr):
    return((arr[3]-arr[1])*(arr[2]-arr[0]))

fout.write(str(area(arr[0])+area(arr[1])-intersection(arr[0],arr[2])-intersection(arr[1],arr[2])))