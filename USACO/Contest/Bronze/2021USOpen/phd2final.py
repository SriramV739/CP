fline=list(int(x) for x in input().strip().split())
test=(input().strip().split())
arr=[]
for i in range(fline[0]):
    arr.append(input().strip().split())

res=[]
dict1={}
for i in range(fline[1]):
    dict1[test[i]]=["?"]*fline[1]
    dict1[test[i]][i]="B"

for i in arr:
    check=[1]
    curr=1
    prev=i[0]
    for j in range(1,len(i)):
        if i[j]<prev:
            curr+=1
        check.append(curr)
        prev=i[j]
    for a in range(len(i)):
        for b in range(len(i)):
            if i[a]!=i[b]:
                if check[a]>check[b]:
                    dict1[i[a]][test.index(i[b])]="1"
                    dict1[i[b]][test.index(i[a])]="0"
                elif check[a]<check[b]:
                    dict1[i[a]][test.index(i[b])]="0"
                    dict1[i[b]][test.index(i[a])]="1"

for i in test:
    s=""
    for j in dict1[i]:
        s+=j
    print(s)
