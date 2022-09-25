fin=open("gymnastics.in")
fout=open("gymnastics.out","w")
line=list(int(x) for x in fin.readline().strip().split())
k=line[0]
n=line[1]
arr=[]
for i in range(k):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
print(arr)
count=0
for i in range(1,n+1):
    for j in range(1,n+1):
        if i!=j:
            res=True
            for a in range(k):
                if arr[a].index(i)<arr[a].index(j):
                    continue
                else:
                    res=False
            if res:
                print(i,j)
                count+=1
fout.write(str(count))
fout.write("\n")