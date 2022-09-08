n=int(input())
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in input().split()))

scramble=["r","p","s"]
def win(a,b):
    if a=="r" and b=="p":
        return(2)
    elif a=="r" and b=="s":
        return(1)
    elif a=="p" and b=="r":
        return(1)
    elif a=="p" and b=="s":
        return(2)
    elif a=="s" and b=="r":
        return(2)
    elif a=="s" and b=="p":
        return(1)
    else:
        return(2)

import itertools
res=[]
for i in list(itertools.permutations(scramble)):
    count=0
    i=list(i)
    for a in arr:
        if win(i[a[0]-1],i[a[1]-1])==1:
            count+=1
    res.append(count)

print(max(res))