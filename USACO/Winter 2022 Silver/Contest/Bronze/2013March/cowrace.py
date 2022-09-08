fin=open("cowrace.in")
fout=open("cowrace.out","w")
n,m=map(int,fin.readline().strip().split())
b=[]
e=[]
for i in range(n):
    b.append(list(int(x) for x in fin.readline().strip().split()))
for i in range(m):
    e.append(list(int(x) for x in fin.readline().strip().split()))

bpt=0
ept=0
prev=-1
btot=0
etot=0
count=0
while True:
    if b[bpt][1]>e[ept][1]:
        btot+=(e[ept][1])*b[bpt][0]
        b[bpt][1]-=e[ept][1]
        etot+=(e[ept][0]*e[ept][1])
        ept+=1
    else:
        etot+=(b[bpt][1])*e[ept][0]
        e[ept][1]-=b[bpt][1]
        btot+=(b[bpt][0]*b[bpt][1])
        bpt+=1
        if e[ept][1]==0:
            ept+=1
    if etot>btot:
        if prev=="b":
            count+=1
        prev="e"
    elif btot>etot:
        if prev=="e":
            count+=1
        prev="b"
    if bpt>=len(b) or ept>=len(e):
        break
    #print(bpt,ept,btot,etot,prev)
fout.write(str(count))
fout.write("\n")
    