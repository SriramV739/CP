n=int(input())
use=[]
east=[]
north=[]
for i in range(n):
    s=input().strip()
    use.append(s)
    s=s.split()
    s[1]=int(s[1])
    s[2]=int(s[2])
    if s[0]=="E":
        east.append(s)
    else:
        north.append(s)
print(north,east)

def time(first,second):
    if first[0]=="E":
        if first[1]<second[1] and first[2]>second[2]:
            if second[1]-first[1]<=first[2]-second[2]:
                res=False
                return False
            else:
                res=(True)
        else:
            return(False)
    else:
        if first[2]<second[2] and first[1]>second[1]:
            if first[1]-second[1]<second[2]-first[2]:
                res=True
        else:
            return(False)
    if res:
        if first[0]=="N":
            return(second[2]-first[2])
        else:
            return(first[1]-second[1])
eastdict={}
northdict={}
for i in north:
    for j in east:
        test1=time(i,j)
        if test1:
            if test1 in northdict:
                northdict[test1][1].append(i)
                northdict[test1][2].append(j)
            else:
                northdict1[test1]=[[i],[j]]
        else:
            test2=time(j,i)
            if test2:
                if test2 in eastdict:
                    northdict[test1][1].append(j)
                    northdict[test1][2].append(i)
                else:
                    eastdict[test]=[[j],[i]]

            


