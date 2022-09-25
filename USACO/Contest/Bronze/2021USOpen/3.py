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
for i in range(25):
    sline.append(random.randint(1,10))
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
def hindexupdate(sline,index,dict1):
    curr=sline[index]
    if curr in dict1:
        dict1[sline[index]]=dict1[sline[index-1]]+1
        for i in range(index,-1,-1):
            if sline[i]==curr:
                dict1[sline[i]]+=1
    else:
        dict1[curr]=sline.index(curr)
j=l
i=0
hindex(sline,True)
print(dict1)
while j>0 and i<len(sline):
    if sline[i]<dict1[sline[i]]:
        print(sline[i])
        h=dict1[sline[i]]
        if i!=0:
            if j>min(dict1[sline[i]],sline[i-1])-sline[i]:
                j-=min(dict1[sline[i]],sline[i-1])-sline[i]
                sline[i]+=min(dict1[sline[i]],sline[i-1])-sline[i]
            else:
                sline[i]+=j
                j=0
        else:
            if j>dict1[sline[i]]-sline[i]:
                j-=dict1[sline[i]]-sline[i]
            else:
                sline[i]+=j
                j=0
        
        dict1[sline[i]]=h
        print(dict1)
    i+=1


dict1={}
hindex(sline,True)
print(dict1)
res=True
test=False
for i in range(len(sline)):
    if sline[i]<dict1[sline[i]]:
        res=False
        if i==0:
            test=True
            break
        if i<sline[i]<dict1[sline[i]] and sline[i]>dict1[sline[i-1]]:
            print(sline[i])
        else:
            print(dict1[sline[i-1]])
        break
if res:
    print(dict1[sline[-1]])
if test:
    if dict1[sline[0]]>sline[0]:
        print(sline[0])
    else:
        print(0)
