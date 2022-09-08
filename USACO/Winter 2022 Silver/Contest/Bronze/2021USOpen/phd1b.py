'''fline=input()
sline=input()
fline=fline.split()
sline=sline.split()
l=int(fline[1])
for i in range(len(sline)):
    sline[i]=int(sline[i])'''
l=5
import random
sline=[]
for i in range(20):
    sline.append(random.randint(1,15))
sline=[15, 15, 14, 14, 13, 13, 13, 11, 10, 9, 8, 7, 7, 6, 4, 3, 2, 2, 1, 1]
print(sorted(sline,reverse=True))
dict1={}
def hindex(sline,dosort):
    if dosort:
        sline.sort(reverse=True)
    for i in range(len(sline)):
        if sline[i] in dict1:
            dict1[sline[i]]+=1
        else:
            dict1[sline[i]]=i+1
def hindexcalc(sline):
    for i in range(len(sline)):
        if sline[i]<dict1[sline[i]]:
            res=False
            if i==0:
                test=True
                break
            elif i<sline[i]<dict1[sline[i]] and sline[i]>dict1[sline[i-1]]:
                return(dict1[sline[i]])
            else:
                return(dict1[sline[i-1]])
            break
    if res:
        return(dict1[sline[-1]])
    if test:
        if dict1[sline[0]]>sline[0]:
            return(sline[0])
        else:
            return(0)
def hindexcalc1(sline):
    for i in range(len(sline)):
        if sline[i]<dict1[sline[i]]:
            res=False
            if i==0:
                test=True
                break
            if i<sline[i]<dict1[sline[i]] and sline[i]>dict1[sline[i-1]]:
                return(sline[i])
            else:
                return(dict1[sline[i-1]])
            break
    if res:
        return(len(sline))
    if test:
        if dict1[sline[0]]>sline[0]:
            return(sline[0])
        else:
            return(0)
hindex(sline,True)
res=True
test=False
first=True
if l!=0:
    while True:
        sline1=sline.copy()
        count=0
        if first:
            first=False
            h=hindexcalc1(sline)
        else:
            h+=1
        while True:
            if h in sline:
                break
            else:
                h+=1
        start=sline.index(h)
        currh=h+1
        print(start,h,currh)
        for i in range(start,currh):
            print(i)
            count+=(currh-sline[i])
            sline[i]=currh
        print(sline)
        if count==l:
            break
        elif count>l:
            sline=sline1
            break
        if count<l:
            sline=sline1
dict1={}
hindex(sline,True)
print(hindexcalc(sline))

