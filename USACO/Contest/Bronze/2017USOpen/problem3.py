fin=open("art.in","r")
fout=open("art.out","w")
n=int(fin.readline())
passed=[]
fail=[]
lines=[]
for i in range(n):
    s=fin.readline()
    lines.append(s)
for i in range(n):
    for j in range(n):
        if lines[i][j] in passed or lines[i][j] in fail:
            continue
        else:
            curr=[i,j]
            max=j
            for a in range(curr[1],n):
                if lines[i][a]==lines[i][j]:
                    max+=1
                else:
                    break