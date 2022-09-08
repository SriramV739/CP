fline=list(int(x) for x in input().strip().split())
a=(input().strip().split())
arr=[]
for i in range(fline[0]):
    arr.append(input().strip().split())

res=[]
dict1={}
for i in range(fline[1]):
    dict1[a[i]]=["?"]*fline[1]
    dict1[a[i]][i]="B"

atest=sorted(a)
for i in atest:
    for j in arr:
        for x in j[:j.index(i)]:
            if x>i:
                dict1[i][a.index(x)]="1"
                dict1[x][a.index(i)]="0"
            for y in j[j.index(i)+1:]:
                if x>i or dict1[i][a.index(x)]=="1":
                    dict1[x][a.index(y)]="0"
                    dict1[y][a.index(x)]="1"
        for x in j[j.index(i)+1:]:
            if x<i:
                dict1[i][a.index(x)]="0"
                dict1[x][a.index(i)]="1"
            for y in j[:j.index(i)]:
                if x<i or dict1[i][a.index(x)]=="0":
                    dict1[x][a.index(y)]="1"
                    dict1[y][a.index(x)]="0"

for i in a:
    s=""
    for j in dict1[i]:
        s+=j
    print(s)
