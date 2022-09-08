import math
fin=open("race.in")
fout=open("race.out","w")
line=list(int(x) for x in fin.readline().strip().split())
(dist1,b)=(line[0],line[1])
for i in range(b):
    dist=dist1
    x=int(fin.readline().strip())
    if int(x*(x+1)/2)>dist:
        val=math.ceil((-1+math.sqrt(1+8*dist)/2))
        fout.write(str(math.ceil((-1+math.sqrt(1+8*dist)/2))))
        print(val)
        fout.write("\n")
    else:
        count=0
        val=int(math.sqrt(((2*dist)+(x**2)+x-2)/2))
        print(val)
        count+=val
        count+=(val-x)
        dist-=int(val*(val+1)//2)
        dist-=int(((val**2)-val-(x**2)+x)/2)
        if dist>0:
            if dist<=val:
                count+=1
            else:
                count+=2

        fout.write(str(count))
        fout.write("\n")
        print(count)
        