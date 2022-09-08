"""
ID: your_id_here
LANG: PYTHON3
TASK: milk
"""
fin=open("milk.in","r")
fout=open("milk.out","w")
fline=fin.readline()
fline=fline.strip().split()
n=int(fline[0])
m=int(fline[1])
cost=[]
for i in range(m):
    s=fin.readline().strip().split()
    cost.append([int(s[0]),int(s[1])])
cost.sort(key=lambda x: x[0]) 
price=0
amount=0
for i in range(len(cost)):
    if cost[i][1]<n:
        amount+=cost[i][1]
        price+=cost[i][0]*cost[i][1]
        n-=cost[i][1]
    else:
        price+=cost[i][0]*n
        amount+=n
        n=0
fout.write(str(price))
fout.write("\n")
