fin=open("geteven.in")
fout=open("geteven.out","w")
n=int(fin.readline().strip())
dict1={}
for i in range(n):
    line=fin.readline().strip().split()
    if line[0] in dict1:
        dict1[line[0]].append(int(line[1])%2)
    else:
        dict1[line[0]]=[int(line[1])%2]
    
print(dict1)

count=0
test="BESIGOM"     
res=[]
for a in list(set(dict1["B"])):
    for b in list(set(dict1["E"])):
        for c in list(set(dict1["S"])):
            for d in list(set(dict1["I"])):
                for e in list(set(dict1["G"])):
                    for f in list(set(dict1["O"])):
                        for g in list(set(dict1["M"])):
                            val=[a,b,c,d,e,f,g]
                            count1=0
                            count2=0
                            count3=0
                            sum=1
                            for i in "BESSIE":
                                count1+=val[test.index(i)]
                                
                            for i in "GOES":
                                count2+=val[test.index(i)]
                            for i in "MOO":
                                count3+=val[test.index(i)]
                            if (count1*count2*count3)%2==0:
                                print(val)
                                for i in range(len(test)):
                                    sum*=dict1[test[i]].count(val[i])
                                count+=sum

fout.write(str(count))
                            