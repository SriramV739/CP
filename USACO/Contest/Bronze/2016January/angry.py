fin=open("angry.in")
fout=open("angry.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    arr.append(int(fin.readline().strip()))
arr.sort()
res=[]






'''for i in range(len(arr)):
    temp=i
    curr=1
    count=1
    #forward
    while True:
        add=0
        j=0
        for j in range(i+1,len(arr)):
            if arr[j]-arr[i]<=curr:
                add+=1
            else:
                j-=1
                break
        if add==0:
            break
        elif j==len(arr)-1:
            count+=add
            break
        else:
            i=j
            curr+=1
            count+=add
    i=temp
    curr=1 
    #backward
    while True:
        add=0
        j=0
        for j in range(i-1,-1,-1):
            if arr[i]-arr[j]<=curr:
                add+=1
            else:
                j+=1
                break
        if add==0:
            break
        elif j==0:
            count+=add
            break
        else:
            i=j
            curr+=1
            count+=add
    res.append(count)

print(res)
print(max(res))
fout.write(str(max(res)))
fout.write("\n")
'''

def total(arr,curr,i,count):
    add=0
    j=0
    for j in range(i+1,len(arr)):
        if arr[j]-arr[i]<=curr:
            add+=1
            if j==len(arr)-1:
                count+=add
                return(count)
        else:
            j-=1
            break
    if add==0:
        return(count)
    else:
        count+=add
        print(1)
        total(arr,curr+1,j,count)

def totalback(arr,curr,i,count):
    add=0
    j=0
    for j in range(i-1,-1,-1):
        if arr[i]-arr[j]<=curr:
            add+=1
            if j==0:
                return(count+add)
        else:
            break
    if add==0:
        return(count)
    else:
        count+=add 
        totalback(arr,curr,j+1,count)


for i in range(len(arr)):
    res.append(total(arr,1,i,1)+totalback(arr,1,i,0))

print(res)