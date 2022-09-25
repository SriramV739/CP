fin=open("pails.in")
fout=open("pails.out",'w')
arr=list(int(x) for x in fin.readline().strip().split())
x=arr[2]//arr[0]
y=arr[2]//arr[1]

res=[]
for i in range(x+1):
    for j in range(y+1):
        if (i*arr[0]+j*arr[1])<=arr[2]:
            res.append(i*arr[0]+j*arr[1])
print(res)
fout.write(str(max(res)))
fout.write("\n")