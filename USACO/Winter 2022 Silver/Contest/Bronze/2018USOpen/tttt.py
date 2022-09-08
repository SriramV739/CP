fin=open("tttt.in","r")
fout=open("tttt.out","w")
all=[]
solo=[]
group=[]
for i in range(3):
    for j in fin.readline().strip():
        all.append(j)
def charnum(l):
    return(len(list(set(l))))
row1=all[:3]
row2=all[3:6]
row3=all[6:]
col1=[all[0],all[3],all[6]]
col2=[all[1],all[4],all[7]]
col3=[all[2],all[5],all[8]]
diag1=[all[0],all[4],all[8]]
diag2=[all[2],all[4],all[6]]
if charnum(row1)==2:
    group.append(list(set(row1)))
if charnum(row1)==1:
    solo.append(list(set(row1)))
if charnum(row2)==1:
    solo.append(list(set(row2)))
if charnum(row2)==2:
    group.append(list(set(row2)))
if charnum(row3)==2:
    group.append(list(set(row3)))
if charnum(row3)==1:
    solo.append(list(set(row3)))
if charnum(col1)==2:
    group.append(list(set(col1)))
if charnum(col2)==2:
    group.append(list(set(col2)))
if charnum(col3)==2:
    group.append(list(set(col3)))
if charnum(diag1)==2:
    group.append(list(set(diag1)))
if charnum(diag2)==2:
    group.append(list(set(diag2)))
if charnum(col1)==1:
    solo.append(list(set(col1)))
if charnum(col2)==1:
    solo.append(list(set(col2)))
if charnum(col3)==1:
    solo.append(list(set(col3)))
if charnum(diag1)==1:
    solo.append(list(set(diag1)))
if charnum(diag2)==1:
    solo.append(list(set(diag2)))
'''

for i in range(0,7,3):
    if len(list(list(set(rows[i:i+3])))==2:
        group+=1
    if len(list(list(set(rows[i:i+3])))==1:
        solo+=1
column=[[rows[0],rows[3],rows[6]],[rows[1],rows[4],rows[7]],[rows[2],rows[5],rows[8]]]
for i in column:
    if len(list(list(set(i)))==2:
        group+=1
    if len(list(list(set(i)))==1:
        solo+=1
diagonal1=[rows[0],rows[4],rows[8]]
diagonal2=[rows[2],rows[4],rows[6]]
if len(list(list(set(diagonal1)))==2:
    group+=1
if len(list(list(set(diagonal1)))==1:
    solo+=1
if len(list(list(set(diagonal2)))==2:
    group+=1
if len(list(list(set(diagonal2)))==1:
    solo+=1'''

print(group)
print(solo)
solodict={}
groupdict={}
for i in solo:
    solodict[str(i)]=1
for i in group:
    groupdict[str(i)]=1



fout.write(str(len(list(solodict.keys()))))
fout.write("\n")
fout.write(str(len(groupdict.keys())))
fout.write("\n")