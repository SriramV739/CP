fin=open("censor.in")
fout=open("censor.out","w")
a=fin.readline().strip()
source=[]
for i in a:
    source.append(i)
b=fin.readline().strip()
rem=[]
for i in b:
    rem.append(i)

i=len(rem)-1
if len(rem)>len(source):
    fout.write(a)
else:
    while i<len(source):
        
        if source[i-len(rem)+1:i+1]==rem:
            del source[i-len(rem)+1:i+1]
            i-=(len(rem)-1)
        else:
            i+=1

    for i in source:
        fout.write(i)
    fout.write("\n")
            