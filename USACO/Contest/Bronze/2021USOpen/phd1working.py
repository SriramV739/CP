fline=list(int(x) for x in input().strip().split())
l=fline[1]
arr=sorted(list(int(x) for x in input().strip().split()),reverse=True)
#findhindex
hindex=0
for i in range(len(arr)):
    if i+1<=arr[i]:
        hindex=i+1
    else:
        break



test=False
hindex+=1
if hindex>len(arr):
    hindex-=1
else:
    count=0
    for i in range(hindex):
        if arr[i]<hindex:
            count+=1
        if max(0,hindex-arr[i])>1:
            test=True
    if test:
        hindex-=1
    elif count>l:
        hindex-=1

print(hindex)

    