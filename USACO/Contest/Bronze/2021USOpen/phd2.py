from os import kill


fline=list(int(x) for x in input().strip().split())
k=fline[0]
n=fline[1]
sline=input().strip().split()
dict1={}
for i in range(len(sline)):
    dict1[sline[i]]=["?"]*n
    dict1[sline[i]][i]="B"

for a in range(k):
    line=input().strip().split()
    for i in range(len(line)):
        for j in range(len(line)):
            if i!=j:
                if i>j and line[i]<line[j]:
                    dict1[line[i]][sline.index(line[j])]="1"
                    dict1[line[j]][sline.index(line[i])]="0"
                elif i<j and line[i]>line[j]:
                    dict1[line[i]][sline.index(line[j])]="0"
                    dict1[line[j]][sline.index(line[i])]="1"

print(dict1)
