import itertools
fin=open("lineup.in")
fout=open("lineup.out","w")
n=int(fin.readline().strip())
arr=[]
for i in range(n):
    line=fin.readline().strip().split()
    arr.append([line[0],line[-1]])

for i in list(list(x) for x in itertools.permutations(sorted(["Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"]))):
    test=True
    for j in arr:
        if abs(i.index(j[0])-i.index(j[1]))!=1:
            test=False
    if test:
        possible=i
        break

for i in possible:
    fout.write(str(i))
    fout.write("\n")