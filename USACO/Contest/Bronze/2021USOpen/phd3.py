fline=input()
fline=fline.split()
rows=[]
for i in range(int(fline[0])):
    line=input()
    rows.append(line)
dict1={}
res=0
test=True
for i in range(len(rows)):
    for j in range(len(rows[i])):
        if rows[i][j]=="G":
            if i!=0 and i!=len(rows)-1:
                if rows[i-1][j]=="C" and rows[i+1][j]=="C":
                    res+=1
                    test=False
            if j!=0 and j!=int(fline[1])-1 and test:
                if rows[i][j+1]=="C" and rows[i][j-1]=="C":
                    res+=1
                    test=False
            around=[]
            if test:
                try:
                    if rows[i+1][j]=="C":
                        around.append(True)
                except IndexError:
                    around.append(False)
                try: 
                    if rows[i][j+1]=="C":
                        around.append(True)
                except IndexError:
                    around.append(False)
                try:
                    if rows[i-1][j]=="C":
                        around.append(True)
                except IndexError:
                    around.append(False)
                try:
                    if rows[i][j-1]=="C":
                        around.append(True)
                except IndexError:
                    around.append(False)
                if around[0] and around[1] and [[i-1,j],[i,j+1]] not in dict1:
                    dict1[[[i-1,j],[i,j+1]]]=1
                    res+=1
                    test=False
                if around[1] and around[2] and [[i,j+1],[i+1,j]] not in dict1 and test:
                    dict1[[[i,j+1],[i+1,j]]]=1
                    res+=1
                    test=False
                if around[2] and around[3] and [[i+1,j],[i],j-1] not in dict1 and test:
                    dict1[[[i+1,j],[i],j-1]]=1
                    res+=1
                    test=False
                if around[3] and around[0] and [[i,j-1],[i-1,j]] not in dict1 and test:
                    dict1[[[i,j-1],[i-1,j]]]=1
                    res+=1
                    test=False
print(res)  