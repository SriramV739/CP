n=int(input())
use=[]
east=[]
north=[]
for i in range(n):
    s=input().strip()
    use.append(s)
def timecheck(use):
    dict1={}
    for i in use:
        finali=i
        dict1[finali]=1000000000
        i=i.split()
        (i[1],i[2])=(int(i[1]),int(i[2]))
        for j in use:
            j=j.split()
            (j[1],j[2])=(int(j[1]),int(j[2]))
            if i!=j and i[0]!=j[0]:
                if i[0]=="N":
                    if i[1]>j[1] and i[2]<j[2]:
                        if j[2]-i[2]>i[1]-j[1]:
                            dict1[finali]=min(dict1[finali],j[2]-i[2])
                else:
                    if j[1]>i[1] and i[2]>j[2]:
                        if j[1]-i[1]>i[2]-j[2]:
                            dict1[finali]=min(j[1]-i[1],dict1[finali])
        if dict1[finali]==1000000000:
            dict1[finali]="inf"
    return(dict1)


res={}
for i in use:
    res[i]="Infinity"


while len(use)!=0:
    dict1=timecheck(use)
    dist=[]
    for i in use:
        if dict1[i]=="inf":
            res[i]="Infinity"
        else:
            dist.append(dict1[i])
    try:
        travel=min(dist)
    except:
        break
    for i in use:
        if dict1[i]==travel:
            res[i]=travel

    use=list(x for x in use if dict1[x]!=travel)
    for i in use:
        i=i.split()
        i[1]=int(i[1])
        i[2]=int(i[2])
        if i[0]=="N":
            i[2]+=travel
        else:
            i[1]+=travel
        i[1]=str(i[1])
        i[2]=str(i[2])
        i=" ".join(i)
    
        
for i in res:
    print(res[i])
