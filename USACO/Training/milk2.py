"""
ID: sriramv3
LANG: PYTHON3
TASK: milk2
"""

fin=open("milk2.in","r")
fout=open("milk2.out","w")
n=int(fin.readline())
dict1={}
for i in range(n):
    s=fin.readline()
    for j in range(len(s)):
        if s[j]==" ":
            if int(s[:j]) not in dict1:
                dict1[int(s[:j])]=int(s[j+1:])
            else:
                dict1[int(s[:j])]=max((int(s[j+1:])),dict1[int(s[:j])])
start=[]
for i in list(dict1.keys()):
    start.append(i)
start.sort()
finish=[]
for i in start:
    finish.append(dict1[i])
count=0
times=[]
idle=[0]
end=finish[0]
for i in range(len(start)):
    if i==0:
        count+=(finish[i]-start[i])
    else:
        if end>=start[i] and finish[i]>end:
            idle.append(0)
            count+=(finish[i]-end)
            end=finish[i]
        elif end<start[i]:
            idle.append(start[i]-end)
            end=finish[i]
            times.append(count)
            count=end-start[i]
if count!=0:
    times.append(count)

fout.write(str(max(times)))
fout.write(" ")
fout.write(str(max(idle)))
fout.write("\n")