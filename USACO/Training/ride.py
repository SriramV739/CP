"""
ID: your_id_here
LANG: PYTHON3
TASK: ride
"""
char="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
fin=open("ride.in","r")
fout=open("ride.out","w")
x=fin.readline().strip()
y=fin.readline().strip()
print(x,y)
count1=1
count2=1
for i in x:
    count1*=(char.index(i)+1)
for i in y:
    count2*=(char.index(i)+1)
if (count1%47)==(count2%47):
    fout.write("GO\n")
else:
    fout.write("STAY\n")
fout.close()
