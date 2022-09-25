fin=open("blocks.in")
fout=open("blocks.out","w")
n=int(fin.readline().strip())
dict1={}
for i in "abcdefghijklmnopqrstuvwxyz":
    dict1[i]=0
for i in range(n):
    line=fin.readline().split()
    for j in set(list(line[0]+line[1])):
        dict1[j]+=max(line[0].count(j),line[1].count(j))
for i in list(dict1.keys()):
    fout.write(str(dict1[i]))
    fout.write("\n")