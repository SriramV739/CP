"""
ID: your_id_here
LANG: PYTHON3
TASK: palsquare
"""
fin=open("palsquare.in","r")
fout=open("palsquare.out","w")
b=int(fin.readline().strip())
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
dict1={}
for i in range(1,301):
    if palindrome(baseConv(i**2,b)):
        dict1[baseConv(i,b)]=baseConv(i**2,b)
for i in list(dict1.keys()):
    fout.write(str(i))
    fout.write(" ")
    fout.write(str(dict1[i]))
    fout.write("\n")