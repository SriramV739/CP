s=input().strip()
odd=False
n=len(s)
if len(s)%2==1:
    odd=True
arr=[]
dict1={}
for i in s:
    arr.append(i)
    if i in dict1:
        dict1[i]+=1
    else:
        dict1[i]=1
test=True
addodd=False
oddval=0
curr=0
for i in dict1:
    if dict1[i]%2==1:
        if odd:
            odd=False
            addodd=True
            oddval=i
        else:
            test=False
            break
    for j in range(dict1[i]//2):
        arr[curr]=i
        arr[n-curr-1]=i
        curr+=1
if addodd:
    arr[n//2]=oddval
if not test:
    print("NO SOLUTION")
else:
    ans=""
    for i in arr:
        ans+=i
    print(ans)