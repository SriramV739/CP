import math
fin=open("whatbase.in")
fout=open("whatbase.out","w")
n=int(fin.readline().strip())

for a in range(n):
    d,e=map(str,fin.readline().strip().split())
    for i in range(10,15001):
        val=(i**2)*int(d[0])+i*int(d[1])+int(d[2])
        a=int(e[0])
        b=int(e[1])
        c=int(e[2])-val
        disc=math.sqrt((b**2)-4*a*c)
        if int(disc)==disc:
            if int((-b+disc)/(2*a))==(-b+disc)/(2*a) and 10<=(-b+disc)/(2*a)<=15000:
                base=[i,int((-b+disc)/(2*a))]
                break
            elif int((-b-disc)/(2*a))==(-b-disc)/(2*a) and 10<=(-b-disc)/(2*a)<=15000:
                base=[i,int((-b-disc)/(2*a))]
                break


    fout.write(str(base[0])+" "+str(base[1]))
    fout.write("\n")