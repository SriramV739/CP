fin=open("notlast.in")
fout=open("notlast.out","w")
n=int(fin.readline().strip().split())
arr=[]
for i in range(n):
    arr.append(fin.readline().strip().split())
    arr[-1]=int(arr[-1])
arr.sort(key=lambda x: x[1])
if len(list(set(list(x[0] for x in arr))))<7:
    if list(x[1] for x in arr).count(arr[0][1])>1:
        fout.write("tie")
    else:
        fout.write(arr[0][0])
else:
    