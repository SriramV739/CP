fin=open("records.in")
fout=open("records.out","w")
dict1={}
for i in range(int(fin.readline().strip())):
    line=fin.readline().strip().split()
    if str(sorted(line)) in dict1:
        dict1[str(sorted(line))]+=1
    else:
        dict1[str(sorted(line))]=1
fout.write(str(max(list(dict1.values()))))
fout.write("\n")