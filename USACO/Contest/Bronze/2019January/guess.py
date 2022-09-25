fin=open("guess.in")
fout=open("guess.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    arr.append(fin.readline().strip().split()[2:])
res=[]
for i in arr:
    for j in arr:
        if i!=j:
            count=0
            for a in i:
                if a in j:
                    count+=1
            res.append(count)
print(res)
fout.write(str(max(res)+1))
fout.write("\n")