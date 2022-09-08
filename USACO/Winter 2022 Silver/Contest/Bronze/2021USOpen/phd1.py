fline=list(int(x) for x in input().strip().split())
n=fline[0]
l=fline[1]
arr=sorted(list(int(x) for x in input().strip().split()),reverse=True)

#finding hindex

for i in range(len(arr)):
    if arr[i]<i+1:
        curr=i
        break
    if i==n-1:
        curr=n
        print(n)

#try for curr+1

if curr!=n:
    if l==0:
        print(curr)
    else:
        needed=0

        for i in range(curr+1):
            needed+=max(0,curr+1-arr[i])

        if needed<=l:
            print(curr+1)
        else:
            print(curr)