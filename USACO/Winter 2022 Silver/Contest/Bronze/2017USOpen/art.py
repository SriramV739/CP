fin=open("art.in")
fout=open("art.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    line=[]
    for j in fin.readline().strip():
        line.append(int(j))
    arr.append(line)

colors=[]
for i in arr:
    colors+=i

colors=list(set(colors))
if 0 in colors:
    colors.remove(0)

def recttrace(color,arr):
    hor=[]
    vert=[]
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j]==color:
                hor.append(i)
                vert.append(j)
    return([min(vert),min(hor),max(vert),max(hor)])

count=0

for c in colors:
    test=True
    for b in colors:
        if b!=c:
            bound=recttrace(b,arr)
            for i in range(bound[1],bound[3]+1):
                for j in range(bound[0],bound[2]+1):
                    if arr[i][j]==c:
                        test=False
                        break
                if not test:
                    break
            if not test:
                break
    if test:
        count+=1

fout.write(str(count))
fout.write("\n")