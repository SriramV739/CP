n=int(input())
use=[]
east=[]
north=[]
coord={}
label={}
for i in range(n):
    s=input().strip()
    coord[i]=s
    label[s]=i
    use.append(s)
    if s[0]=="E":
        east.append(s)
    else:
        north.append(s)





def time2(first,second):
    retarr=[0,0]
    if first[1]<second[1] and first[2]>second[2]:
        if second[1]-first[1]<first[2]-second[2]:
            retarr[0]="s"  #second getting stopped
            retarr[1]=first[2]-second[2]
        elif second[1]-first[1]>first[2]-second[2]:
            retarr[0]="f"   #first getting stopped
            retarr[1]=second[1]-first[1]
    return(retarr)


dict1={}
for i in east:
    i1=i.split()
    i1[1]=int(i1[1])
    i1[2]=int(i1[2])
    for j in north:
        j1=j.split()
        j1[1]=int(j1[1])
        j1[2]=int(j1[2])
        val=time2(i1,j1)
        if val[0]=="f":
            if val[1] in dict1:
                dict1[val[1]][0].append(label[i])
                dict1[val[1]][1].append(label[j])
            else:
                dict1[val[1]]=[[label[i]],[label[j]]]
        if val[0]=="s":
            if val[1] in dict1:
                dict1[val[1]][0].append(label[j])
                dict1[val[1]][1].append(label[i])
            else:
                dict1[val[1]]=[[label[j]],[label[i]]]

"""cows=[]
time=[]
cause=[]

print(dict1)
for i in cows:
    amount=0
    for j in cause:
        if i==j:
            amount+=1
    if cows[0] not in final:
        final[cows[0]]=time[0]
    del cows[0]
    del cause[0]
    del time[0]
    for a in range(amount):
        del cows[cause.index(i)]
        del time[cause.index(i)]
        cause.remove(i)
final={}

for i in range(len(cows)):
    final[cows[i]]=time[i]


for i in use:
    if i in final:
        print(final[i])
    else:
        print("Infinity")"""


final={}
"""print(dict1)
print(sorted(list(dict1.keys())))"""
for i in sorted(list(dict1.keys())):
    if dict1[i]!=[[],[]]:
        l=dict1[i]
        for j in range(len(l[0])):
            k=coord[l[0][j]]
            if k not in final:
                final[k]=i

            for a in list(dict1.keys()):
                if a!=i:
                    b=dict1[a]
                    if l[0][j] in b[1]:
                        first=coord[l[0][j]].split()
                        third=coord[b[0][b[1].index(l[0][j])]].split()

                        first[1]=int(first[1])
                        first[2]=int(first[2])
                        third[1]=int(third[1])
                        third[2]=int(third[2])
                        
                        if first[0]=="E":
                            if i<third[1]-first[1]:
                                del dict1[a][0][b[1].index(l[0][j])]
                                del dict1[a][1][b[1].index(l[0][j])]
                        else:
                            if i<third[2]-first[2]:
                                del dict1[a][0][b[1].index(l[0][j])]
                                del dict1[a][1][b[1].index(l[0][j])]
                    

for i in use:
    if i in final:
        print(final[i])
    else:
        print("Infinity")









"""n=int(input())
arr=[]
east=[]
north=[]
for i in range(n):
    s=input().strip().split()
    s[1]=int(s[1])
    s[2]=int(s[2])
    #print(s)
    arr.append(s)
    if s[0] == "E":
        east.append([s[1],s[2]])
    elif s[0] == "N":
        north.append([s[1],s[2]])

print(east)
print(north)
print("Hello")
#print(arr)
stop={}
cause={}
for i in east:
    for j in north:
        print("Hello",i,j)
        if i[0] < j[0] and i[1] > j[1]:
            if j[0] - i[0] > i[1] - j[1] :
                dist=(i[1]-j[1])
                if dist in stop:
                    
                    stop[dist].append(j)
                    cause[dist].append(i)
                else:
                    stop[dist]=j
                    cause[dist]=i

            elif j[0] - i[0] < i[1] - j[1]:
                dist=(j[0]-i[0])
                if dist in stop:
                    stop[dist].append(i)
                    cause[dist].append(j)
                else:
                    stop[dist]=i
                    cause[dist]=j

#print(stop,cause)
            
'''
def contact(first,second):
    if first[0]=="E":
        if first[1]<second[1] and first[2]>second[2]:
            if second[1]-first[1]<=first[2]-second[2]:
                return(False)
            else:
                return(True)
    else:
        if first[2]<second[2] and first[1]>second[1]:
            if first[1]-second[1]<=second[2]-first[2]:
                return(True)
            else:
                return(False)

dict1={}
for i in arr:
    for j in arr:
        if i!=j:
            if i[0]!=j[0]:
                f=i[0]+" "+str(i[1])+" "+str(i[2])
                s=j[0]+" "+str(j[1])+" "+str(j[2])
                if contact(i,j):
                    if f in dict1:
                        dict1[f].append(s)
                    else:
                        dict1[f]=[s]
    if i[0]=="N":
        dict1[s].sort(key=lambda x: x[1])
    else:
        dict1[s].sort(key=lambda x: x[0])
cows=[]
cause=[]      
dict2={}
for i in list(dict1.keys()):
    count=[]
    for j in dict1[i]:
        if i[0]=="N":
            if (int(j.split()[2])-int(i.split()[2])) in dict2:
                dict2[int(j.split()[2])-int(i.split()[2])].append(i)
                dict2[int(j.split()[2])-int(i.split()[2])].append(j)
            else:
                dict2[int(j.split()[2])-int(i.split()[2])]=[i,j]
        else:
            if int(j.split()[1])-int(i.split()[1]) in dict2:
                dict2[int(j.split()[1])-int(i.split()[1])].append(i)
                dict2[int(j.split()[1])-int(i.split()[1])].append(j)
            else:
                dict2[int(j.split()[1])-int(i.split()[1])]=[i,j]


final={}
l=sorted(list(dict2.keys()))
for i in range(0,len(l),2):
    for j in range(0,len(dict2[l[i]]),2):
        cows.append(dict2[l[i]][j])
        cause.append(dict2[l[i]][j+1])
print(cows)
print(cause)
print(dict1)
print(dict2)
'''
"""