"""
ID: your_id_here
LANG: PYTHON3
TASK: gift1
"""
fin=open("gift1.in","r")
fout=open("gift1.out","w")
money={}
content=[]
for i in fin:
    content.append(i.strip())
for i in range(1,int(content[0])+1):
    money[content[i]]=0
i=int(content[0])+1
while i<len(content):
    ptr=0
    while content[i+1][ptr]!=" ":
        ptr+=1
    if int(content[i+1][ptr+1:])!=0:
        money[content[i]]+=int(content[i+1][:ptr])%int(content[i+1][ptr+1:])-int(content[i+1][:ptr])
        for j in range(i+2,i+2+int(content[i+1][ptr+1:])):
            money[content[j]]+=int(content[i+1][:ptr])//int(content[i+1][ptr+1:])
    i+=2+int(content[i+1][ptr+1:])
for i in money:
    fout.write(i)
    fout.write(" ")
    fout.write(str(money[i]))
    fout.write("\n")