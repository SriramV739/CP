n=int(input().strip())
s=input().strip()
count=0
arr=[]
add=0
for i in range(len(s)):
    if s[i]=="G":
        add+=1
    else:
        arr.append(add)
        add=0
arr.append(add)
for i in range(len(arr)-1):
    if arr[i]==0:
        if arr[i+1]!=0:
            count+=(arr[i+1]-1)
    elif arr[i+1]==0:
        if arr[i]!=0:
            count+=(arr[i]-1)
    else:
        count+=((arr[i]+1)*(arr[i+1]+1)-3)
arr=[]
add=0
for i in range(len(s)):
    if s[i]=="H":
        add+=1
    else:
        arr.append(add)
        add=0
arr.append(add)
for i in range(len(arr)-1):
    if arr[i]==0:
        if arr[i+1]!=0:
            count+=(arr[i+1]-1)
    elif arr[i+1]==0:
        if arr[i]!=0:
            count+=(arr[i]-1)
    else:
        count+=((arr[i]+1)*(arr[i+1]+1)-3)

print(count)