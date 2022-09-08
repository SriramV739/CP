fin=open("promote.in")
fout=open("promote.out","w")
arr=[]
for i in range(4):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
res=[0]
count=0

for i in range(3,0,-1):
    res.append(arr[i][1]+res[-1]-arr[i][0])


'''res.append(arr[-1][1]-arr[-1][0])
res.append(arr[2][1]+res[0]-arr[2][0])
res.append(arr[1][1]+res[1]-arr[1][0])'''
res=res[1:]
print(res)
for i in range (len(res)-1,-1,-1):
    fout.write(str(res[i]))
    fout.write("\n")