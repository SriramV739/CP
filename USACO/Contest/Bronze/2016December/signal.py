fin=open("cowsignal.in")
fout=open("cowsignal.out","w")
f=fin.readline().strip().split()
(m,n,k)=(int(f[0]),int(f[1]),int(f[2]))
for j in range(m):
    line=fin.readline().strip()
    for b in range(k):
        for i in line:
            for a in range(k):
                fout.write(i)
        fout.write("\n")