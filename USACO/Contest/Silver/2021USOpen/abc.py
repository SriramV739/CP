from itertools import combinations
import itertools
t=int(input().strip())
for a in range(t):
    ans=[]
    n=int(input().strip())
    arr=list(int(x) for x in input().strip().split())
    arr1=arr.copy()
    for i in arr:
        for j in arr:
            if i!=j:
                arr1.append(abs(i-j))
    for i in list(itertools.combinations(arr1,3)):
        i=list(i)
        i.sort()
        a=i[0]
        b=i[1]
        c=i[2]
        check=[]
        for j in i:
            check.append(j)
        check.append(b+a)
        check.append(c+a)
        check.append(b+c)
        check.append(a+b+c)
        test=True
        for j in arr:
            if j not in check:
                test=False
                break
        if test:
            ans.append((str(i)))
    print(len(list(set(ans))))