fin=open("odometer.in")
fout=open("odometer.out","w")
r,s=map(int,fin.readline().strip().split())
i=0
while True:
    if 10**i<=r:
        i+=1
    else:
        less=i-1
        break
i=16
while True:
    if 10**i>=s:
        i-=1
    else:
        greater=i+1
        break
all=[]
total=81*(greater-less)*(greater+less-1)/2
for i in range(less+1,greater+1):
    for j in range(i):
        for a in range(1,10):
            for b in range(1,10):
                if a!=b:
                    all.append([])
                    for x in range(i):
                        all[-1].append(b)
                    all[-1][j]=a

    for j in range(1,10):
        all.append([])
        for x in range(i):
            all[-1].append(0)
        all[-1][0]=j
    for j in range(1,i):
        for k in range(1,10):
            all.append([])
            for x in range(i):
                all[-1].append(k)
            all[-1][j]=0
count=len(all)
for i in all:
    q=""
    for j in i:
        q+=str(j)
    x=int(q)
    if x<r or x>s:
        count-=1

fout.write(str(count))
fout.write("\n")

