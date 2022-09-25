import math
fin=open("race.in")
fout=open("race.out","w")
line=list(int(x) for x in fin.readline().strip().split())
(dist,n)=(line[0],line[1])
for i in range(n):
    speed=int(fin.readline().strip())
    val=int(math.sqrt((2*dist+(speed)**2-speed)/2))
    val2=val
    rem=dist-(val)*(val+1)//2
    sum2=0
    count=0
    while sum2<rem:
        if rem-sum2>=(val+speed)*(val-speed+1)//2:
            count+=1
        else:
            count+=1
            val-=1
        sum2+=val
    fout.write(str(count+val2))
    fout.write("\n")