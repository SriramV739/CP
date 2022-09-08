import math
fin=open("herding.in")
fout=open("herding.out","w")
arr=sorted(list(int(x) for x in fin.readline().strip().split()))
(b,e,m)=(arr[0],arr[1],arr[2])
if b==e-1 and e==m-1:
    fout.write("0")
    fout.write("\n")
    fout.write("0")
    fout.write("\n")
else:
    if min(abs(e-m),abs(m-b))==2:
        fout.write("1")
    else:
        fout.write("2")
    fout.write("\n")
    print((max(abs(e-m),abs(e-b))))
    fout.write(str(max(abs(e-m),abs(e-b))-1))
    fout.write("\n")