fin=open("reduce.in")
fout=open("reduce.out","w")
n=int(fin.readline().strip())
cornercheck=[40000,40000,0,0]
corners=[]
arr=[]
for i in range(n):
    line=list(int(x) for x in fin.readline().strip().split())
    arr.append(line)
"""    if line[0]<cornercheck[0]:
        cornercheck[0]=line[0]
        corners.append(line)
    if line[1]<cornercheck[1]:
        cornercheck[1]=line[1]
        corners.append(line)
    if line[0]>cornercheck[2]:
        cornercheck[2]=line[0]
        corners.append(line)
    if line[1]>cornercheck[3]:
        cornercheck[3]=line[1]
        corners.append(line)

"""

corners.append(sorted(arr,key=lambda x: x[0])[0])
corners.append(sorted(arr,key=lambda x: x[0])[-1])
corners.append(sorted(arr,key=lambda x: x[1])[0])
corners.append(sorted(arr,key=lambda x: x[1])[-1])

def area(arr,bad):
    x=(list(i[0] for i in arr if i!=bad))
    y=(list(i[1] for i in arr if i!=bad))
    return((max(x)-min(x))*(max(y)-min(y)))

res=[]
for i in corners:
    res.append(area(arr,i))





fout.write(str(min(res)))
fout.write("\n")