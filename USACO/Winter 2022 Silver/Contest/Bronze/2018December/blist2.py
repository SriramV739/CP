fin=open("blist.in")
fout=open("blist.out","w")
dict1={}
for i in range(int(fin.readline().strip())):
    line=list(int(x) for x in fin.readline().strip().split())
    dict1[line[0]]=[line[2],"s"]
    dict1[line[1]]=[line[2],"e"]
bucket=0
res=0
for i in sorted(list(dict1.keys())):
    val=dict1[i]
    if val[-1]=="e":
        bucket+=val[0]
    else:
        if bucket<=val[0]:
            res+=val[0]-bucket
            bucket=0
        else:
            bucket-=val[0]

fout.write(str(res))
fout.write("\n")