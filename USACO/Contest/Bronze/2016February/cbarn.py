fin=open("cbarn.in")
fout=open("cbarn.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    arr.append(int(fin.readline().strip()))
print(arr)
pos=0
count=[]
for pos in range(n):
    mult=0
    res=0
    for i in range(pos,len(arr)):
        res+=(arr[i]*mult)
        mult+=1
    for i in range(pos):
        res+=(arr[i]*mult)
        mult+=1
    count.append(res)

fout.write(str(min(count)))
fout.write("\n")

