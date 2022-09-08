"""
ID: your_id_here
LANG: PYTHON3
TASK: namenum
"""
names=open("dict.txt","r")
fin=open("namenum.in","r")
fout=open("namenum.out","w")
dict1={ "2": "ABC",     "5": "JKL" ,   "8": "TUV",
          "3": "DEF"   ,  "6": "MNO" ,   "9": "WXY",
          "4": "GHI",     "7": "PRS"}
n=fin.readline().strip()
res=[]
for i in range(5000):
    add=True
    s=names.readline().strip()
    if s=="":
        break
    if len(s)==len(n):
        for j in range(len(n)):
            if s[j] not in dict1[n[j]]:
                add=False
                break
        if add:
            res.append(s)
if len(res)==0:
    fout.write("NONE")
    fout.write("\n")
else: 
    for i in res:
        fout.write(i)
        fout.write("\n")