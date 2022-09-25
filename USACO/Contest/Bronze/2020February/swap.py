fin=open("swap.in")
fout=open("swap.out","w")
line1=list(int(x) for x in fin.readline().strip().split())
n=line1[0]
k=line1[1]
line2=list(int(x) for x in fin.readline().strip().split())
a1=line2[0]
a2=line2[1]
line3=list(int(x) for x in fin.readline().strip().split())
b1=line3[0]
b2=line3[1]
res=[0]*n

for i in range(1,n+1):
    arr=list(x for x in range(1,n+1))
    values=[i]
    while True:
        arr[a1-1:a2]=arr[a1-1:a2][::-1]
        arr[b1-1:b2]=arr[b1-1:b2][::-1]
        place=arr.index(i)+1
        if place==i:
            break
        values.append(place)
    
    res[values[k%len(values)]-1]=i

for i in res:
    fout.write(str(i))
    fout.write("\n")
