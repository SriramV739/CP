fin=open("word.in","r")
fout=open("word.out","w")
l=fin.readline().strip().split()
n=int(l[0])
k=int(l[1])
arr=fin.readline().strip().split()
count=0
line=[]
for i in arr:
    count+=len(i)
    if count>k:
        for j in range(len(line)):
            fout.write(str(line[j]))
            if j==len(line)-1:
                fout.write("\n")
            else:
                fout.write(" ")
        line=[i]
        count=len(i)
    else:
        line.append(i)

for j in range(len(line)):
            fout.write(str(line[j]))
            if j==len(line)-1:
                fout.write("\n")
            else:
                fout.write(" ")
