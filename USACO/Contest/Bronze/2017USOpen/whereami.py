fin=open("whereami.in")
fout=open("whereami.out","w")
n=int(fin.readline().strip())
s=fin.readline().strip()
i=0
for i in range(1,n+1):
    dict1={}
    test=True
    for j in range(n-i+1):
        if s[j:j+i] not in dict1:
            dict1[s[j:j+i]]=1
        else:
            test=False
            break
    if test:
        fout.write(str(i))
        fout.write("\n")
        exit()