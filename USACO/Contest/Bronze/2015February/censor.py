fin=open("censor.in")
fout=open("censor.out","w")
f=fin.readline().strip()
s=fin.readline().strip()
res=""
for i in range(len(f)):
    res+=(f[i])
    if len(res)>=len(s):
        if res[len(res)-len(s):]==s:
            res=res[:len(res)-len(s)]

fout.write(res)
fout.write("\n")