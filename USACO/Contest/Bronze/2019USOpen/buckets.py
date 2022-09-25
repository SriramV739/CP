fin=open("buckets.in","r")
fout=open("buckets.out","w")
for i in range(10):
    line=fin.readline()
    if "B" in line:
        b=[line.index("B")+1,i+1]
    if "R" in line:
        r=[line.index("R")+1,i+1]
    if "L" in line:
        l=[line.index("L")+1,i+1]
print(b)
print(l)
print(r)
if b[1]==l[1]==r[1]:
    if b[0]<r[0]<l[0] or b[0]>r[0]>l[0]:
        fout.write(str(abs(b[0]-l[0])+1))
    else:
        fout.write(str(abs(b[0]-l[0])-1))
elif b[0]==l[0]==r[0]:
    if b[1]<r[1]<l[1] or b[1]>r[1]>l[1]:
        fout.write(str(abs(b[1]-l[1])+1))
    else:
        fout.write(str(abs(b[1]-l[1])-1))
else:
    fout.write(str(abs(b[1]-l[1])+abs(b[0]-l[0])-1))
fout.write("\n")