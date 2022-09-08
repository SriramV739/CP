import math
fin=open("learning.in")
fout=open("learning.out","w")
line=list(int(x) for x in fin.readline().strip().split())
l=[]
for i in range(line[0]):
    l.append(fin.readline().strip().split())
    l[-1][-1]=int(l[-1][-1])

l.sort(key=lambda x: x[-1])
print(l)
arr=[]
i=0
for i in range(len(l)):
    if line[1]<=l[i][1]:
        break
try:
    del arr[:i]
except:
    pass

for i in range(len(l)):
    if l[i][1]<=line[2]:
        break

try:
    del arr[i+1:]
except:
    pass

count=0
if arr[0][0]=="S" and line[0]<=arr[0][1]:
    count+=(arr[0][1]-line[1])
if arr[-1][0]=="S" and line[1]>=arr[-1][1]:
    count+=(line[-1]-arr[-1][-1])

if arr[0][1]<=line[1]:
    if arr[0][0]=="NS":
        if arr[1][0]=="S":
            if math.ceil((arr[1][1]+arr[0][1]/2)>=line[1]):
                count+=arr[1][1]-math.ceil(arr[1][1]+arr[0][1]/2)
            else:
                count+=arr[1][1]-line[1]
    else:
        if arr[1][0]=="S":
            count+=arr[1][1]-line[1]
        else:
            

print(count)
for i in range(len(arr)-1):
    a=arr[i]
    b=arr[i+1]
    if a[0]=="S":
        if b[0]=="S":
            count+=(b[1]-a[1]-1)
        else:
            count+=((math.floor((a[1]+b[1])/2))-a[1])
            print(count)

    if a[0]=="NS":        
        if b[0]=="S":
            count+=(b[1]-math.ceil((a[1]+b[1])/2))
        
for i in arr:
    if i[0]=="S":
        count+=1

fout.write(str(count))
fout.write("\n")