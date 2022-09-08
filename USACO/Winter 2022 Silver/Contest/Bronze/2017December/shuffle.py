fin=open("shuffle.in","r")
fout=open("shuffle.out","w")
n=int(fin.readline().strip())
shuffle=fin.readline().strip().split()
order=fin.readline().strip().split()
for i in range(n):
    pos=int(shuffle[i])
    for i in range(2):
        pos=int(shuffle[pos-1])
    fout.write(order[pos-1])
    fout.write("\n")