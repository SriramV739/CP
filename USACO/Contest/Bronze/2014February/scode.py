fin=open("scode.in")
fout=open("scode.out","w")
line=fin.readline().strip()
count=0
def rec(s):
    global count
    if len(s)<=2:
        return()
    else:
        first=s[:len(s)//2]
        second=s[len(s)//2:]
        if first==second[:-1]:
            count+=1
            rec(second)
        if first==second[1:]:
            count+=1
            rec(second)
        first=s[:len(s)//2+1]
        second=s[len(s)//2+1:]
        if first[1:]==second:
            count+=1
            rec(first)
        if first[:-1]==second:
            count+=1
            rec(first)

rec(line)
fout.write(str(count))
fout.write("\n")
