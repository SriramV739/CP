fin=open("scode.in")
fout=open("scode.out","w")
line=fin.readline()
global count
count=0
arr=[]
def rec(s):
    global count
    if len(s)<=2 or len(s)%2==0:
        return()
    else:
        first=s[:len(s)//2:]
        second=s[len(s)//2:]
        if first==second[:-1]:
            count+=1
            arr.append(1)
            rec(second)
        if first==second[1:]:
            count+=1
            arr.append(1)
            rec(second)
        first=s[:len(s)//2+1:]
        second=s[len(s)//2+1:]
        if first[1:]==second:
            count+=1
            arr.append(1)
            rec(first)
        if first[:-1]==second:
            count+=1
            arr.append(1)
            rec(first)

rec(line)
fout.write(str(len(arr)))
fout.write("\n")
