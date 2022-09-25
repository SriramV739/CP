fin=open("backforth.in")
fout=open("backforth.out","w")
fline=list(int(x) for x in fin.readline().strip().split())
sline=list(int(x) for x in fin.readline().strip().split())
dict1={}
dict2={}
for i in range(10):
    if fline[i] in dict1:
        dict1[fline[i]]+=1
    else:
        dict1[fline[i]]=1
    if sline[i] in dict2:
        dict2[sline[i]]+=1
    else:
        dict2[sline[i]]=1

def switch(i,today,tomorrow):
    today[i]-=1
    if i in tomorrow:
        tomorrow[i]+=1
    else:
        tomorrow[i]=1
    if today[i]==0:
        del today[i]
res=[]

for i in list(dict1.keys()):
    mon=dict1
    tues=dict2
    switch(i,mon,tues)
    count=0
    count-=i
    for j in list(tues.keys()):
        count1=count
        wed=mon
        switch(j,tues,wed)
        count1+=j
        for a in list(wed.keys()):
            count2=count1
            count2-=a
            thurs=tues
            switch(a,wed,thurs)

            for b in list(thurs.keys()):
                count3=count2
                count3+=b
                fri=wed
                switch(b,thurs,fri)
                res.append([count3,i,j,a,b])
print(res)
fout.write(str(len(set(res))))
fout.write("\n")
