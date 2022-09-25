fin=open("auto.in")
fout=open("auto.out","w")
w,n=map(int,fin.readline().split())
arr=[]
dict1={}
for i in range(w):
    line=fin.readline()
    dict1[line]=i+1
    arr.append(line)
partial=[]
for i in range(n):
    line=fin.readline().split()
    print(line)
    line[0]=int(line[0])
    partial.append(line)

arr.sort()
for i in partial:
    count=0
    test=True
    for j in arr:
        if len(j)>=len(i[1]):
            if j[:len(i[1])]==i[1]:
                count+=1
                if count==i[0]:
                    fout.write(str(dict1[j]))
                    fout.write("\n")
                    test=False
                    break
    if test:
        fout.write("-1")
        fout.write("\n")