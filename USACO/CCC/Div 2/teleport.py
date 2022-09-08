n=int(input())
res=0
arr=[]
subt=0
for i in range(n):
    line=list(int(x) for x in (input().split()))
    a=line[0]
    b=line[1]
    if abs(a-b)<=abs(a):
        res+=(abs(a-b))
    else:
        c=abs(a-b)-abs(a)
        arr.append([b,-2])
        arr.append([b-c,1])
        arr.append([b+c,1])
        res+=abs(a-b)
        

arr.sort(key=lambda x: x[0])
greatest=0
prev=0
save=0
curr=0
for i in arr:
    save+=(i[0]-prev)*curr
    prev=i[0]
    curr+=i[1]
    if greatest<save:
        greatest=save

print(res-greatest)