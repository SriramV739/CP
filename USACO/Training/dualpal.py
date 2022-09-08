"""
ID: your_id_here
LANG: PYTHON3
TASK: dualpal
"""
fin=open("dualpal.in","r")
fout=open("dualpal.out","w")
s=fin.readline()
s=s.strip().split()
k=int(s[0])
n=int(s[1])
def baseConv(n,b):
    res1=[]
    while True:
        rem=n%b
        res1.append(rem)
        n=n//b
        if n<b:
            res1.append(n)
            break
    res=""
    arr=["A","B","C","D","E","F","G","H","I","J","K"]
    for i in range(len(res1)-1,-1,-1):
        if res1[i]>9:
            res+=(arr[res1[i]-10])
        else:
            res+=str(res1[i])
    res=res.lstrip("0")
    return(res)
def palindrome(s):
    if len(s)==1:
        return(True)
    else:
        s1=""
        s2=""
        for i in range(len(s)-1,-1,-1):
            s1+=s[i]
        for i in range(len(s)):
            s2+=s[i]
        if s1==s2:
            return(True)
        else:
            return(False)
total=0
res=[]
n+=1
while True:
    count=0
    for i in range(2,11):
        if palindrome(str(baseConv(n,i))):
            count+=1
        if count==2:
            total+=1
            res.append(n)
            break
    n+=1
    if total==k:
        break
for i in res:
    fout.write(str(i))
    fout.write("\n")
    
