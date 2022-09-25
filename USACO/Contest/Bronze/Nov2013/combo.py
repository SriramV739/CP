fin=open("combo.in")
fout=open("combo.out","w")
n=int(fin.readline().strip())
a=list(int(x) for x in fin.readline().strip().split())
b=list(int(x) for x in fin.readline().strip().split())
vals=[]
for x in [a[0]-2,a[0]-1,a[0],a[0]+1,a[0]+2]:
    for y in [a[1]-2,a[1]-1,a[1],a[1]+1,a[1]+2]:
        for z in [a[2]-2,a[2]-1,a[2],a[2]+1,a[2]+2]:
            if x<=0:
                x+=n
            if x>n:
                x-=n
            if y<=0:
                y+=n
            if y>n:
                y-=n
            if z>n:
                z-=n
            if z<=0:
                z+=n
            if 1<=x<=n and 1<=y<=n and 1<=z<=n:
                vals.append([x,y,z])

for x in [b[0]-2,b[0]-1,b[0],b[0]+1,b[0]+2]:
    for y in [b[1]-2,b[1]-1,b[1],b[1]+1,b[1]+2]:
        for z in [b[2]-2,b[2]-1,b[2],b[2]+1,b[2]+2]:
            if x<=0:
                x+=n
            if x>n:
                x-=n
            if y<=0:
                y+=n
            if y>n:
                y-=n
            if z>n:
                z-=n
            if z<=0:
                z+=n
            if 1<=x<=n and 1<=y<=n and 1<=z<=n:
                vals.append([x,y,z])
print(vals)
fout.write(str(len(list(set(list(str(x) for x in vals))))))
fout.write("\n")