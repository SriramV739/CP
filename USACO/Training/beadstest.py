fin=open("beads.in","r")
fout=open("beads.out","w")
n=int(fin.readline())
beads=fin.readline()
nums=[]






import time
start=time.time()
for i in range(n):
    if beads.count(beads[i])==n:
        break
    if beads[i]=="w":
        continue
    count=0
    color1=[beads[i],"w"]
    j=i-1
    if j==-1:
        j=n-1
    color2=[beads[j],"w"]
    while beads[i] in color1 and beads[j] in color2:
        count+=2
        i+=1
        j-=1
        if i==n:
            i=0
        if j==-1:
            j=n-1
    while beads[i] in color1:
            count+=1
            i+=1
            if i==n:
                i==0
    while beads[j] in color2:
            count+=1
            j-=1
            if j==-1:
                j=n-1
    nums.append(count)
if len(nums)==0:
    fout.write(str(n))
    fout.write("\n")
else:
    fout.write(str(max(nums)))
    fout.write("\n")

print(time.time()-start)
