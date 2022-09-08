"""
ID: your_id_here
LANG: PYTHON3
TASK: barn1
"""
fin=open("barn1.in","r")
fout=open("barn1.out","w")
fline=fin.readline().strip().split()
boards=int(fline[0])
stalls=int(fline[1])
cows=int(fline[2])
arr=[]
for i in range(stalls):
    arr.append(0)
for i in range(cows):
    s=fin.readline().strip()
    arr[int(s)-1]=1
gaps=[]
res=0
count=0
for i in range(arr.index(1),len(arr)-(arr[::-1].index(1))):
    res+=1
    if arr[i]==1:
        if count!=0:
            gaps.append(count)
            count=0
    else:
        count+=1
used=0
curr=0
gaps.sort(reverse=True)
for i in range(boards-1):
    if curr==len(gaps):
        break
    res-=gaps[curr]
    curr+=1
fout.write(str(res))
fout.write("\n")

