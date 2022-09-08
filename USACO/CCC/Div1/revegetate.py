line=list(int(x) for x in input().strip().split())
dict1={}
for i in range(line[1]):
    s=list(int(x) for x in input().strip().split())
    if s[0] in dict1:
        dict1[s[0]].append(s[1])
    else:
        dict1[s[0]]=[s[1]]
    if s[1] in dict1:
        dict1[s[1]].append(s[0])
    else:
        dict1[s[1]]=[s[0]]

res=[]

for i in range(1,line[0]+1):
    if i in dict1:
        l=list(set(list(res[x-1] for x in dict1[i] if x<i)))
        if i==6:
            print(l)
        if len(l)==0:
            res.append(1)
        else:
            l.sort()
            ref=list(i for i in range(1,len(l)+1))
            if l==ref:
                res.append(l[-1]+1)
            else:
                for i in range(len(l)):
                    if l[i]!=ref[i]:
                        res.append(ref[i])
                        break
    else:
        res.append(1)
s=""
for i in res:
    s+=str(i)
print(s)

'''fin=open("revegetate.in")
fout=open("revegetate.out","w")
line=list(int(x) for x in fin.readline().strip().split())
dict1={}
for i in range(line[1]):
    s=list(int(x) for x in fin.readline().strip().split())
    if s[0] in dict1:
        dict1[s[0]].append(s[1])
    else:
        dict1[s[0]]=[s[1]]
    if s[1] in dict1:
        dict1[s[1]].append(s[0])
    else:
        dict1[s[1]]=[s[0]]

res=[]

for i in range(1,line[0]+1):
    if i in dict1:
        l=list(set(list(res[x-1] for x in dict1[i] if x<i)))
        if i==6:
            print(l)
        if len(l)==0:
            res.append(1)
        else:
            l.sort()
            ref=list(i for i in range(1,len(l)+1))
            if l==ref:
                res.append(l[-1]+1)
            else:
                for i in range(len(l)):
                    if l[i]!=ref[i]:
                        res.append(ref[i])
                        break
    else:
        res.append(1)
s=""
for i in res:
    s+=str(i)
print(s)
fout.write(s)
fout.write("\n")'''