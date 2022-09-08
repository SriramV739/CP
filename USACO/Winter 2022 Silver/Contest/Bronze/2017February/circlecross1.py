fin=open("circlecross.in")
fout=open("circlecross.out","w")
s=fin.readline().strip()
line=[]
for i in s:
    line.append(i)
def secondindex(i,arr):
    count=0
    for j in range(len(arr)):
        if arr[j]==i:
            count+=1
        if count==2:
            return(j)
alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
count=0
for i in alphabet:
    for j in alphabet:
        if i!=j:
            if line.index(i)<line.index(j)<secondindex(i,line)<secondindex(j,line):
                count+=1
fout.write(str(count))
fout.write("\n")