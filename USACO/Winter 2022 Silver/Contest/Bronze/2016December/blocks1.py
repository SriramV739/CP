fin=open("blocks.in")
fout=open("blocks.out","w")
char="abcdefghijklmnopqrstuvwxyz"
dict1={}
n=int(fin.readline().strip())
for j in range(n):
    line=fin.readline().strip().split()
    for i in char:
        val=max(line[0].count(i),line[1].count(i))
        if i in dict1:
            dict1[i]+=val
        else:
            dict1[i]=val


for i in sorted(list(dict1.keys())):
    fout.write(str(dict1[i]))
    fout.write("\n")