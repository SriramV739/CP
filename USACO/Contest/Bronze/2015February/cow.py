fin=open("cow.in")
fout=open("cow.out","w")
n=int(fin.readline().strip())
s=fin.readline().strip()
(w,o,c)=(0,0,0)
for i in range(len(s)-1,-1,-1):
    a=s[i]
    if a=="W":
        w+=1
    elif a=="O":
        o+=w
    else:
        c+=o

fout.write(str(c))
fout.write("\n")