line=list(int(x) for x in input().split())
line.sort()
if line[2]-line[1]==2 or line[0]-line[1]==-2:
    print(1)
else:
    print(2)
print(max(line[2]-line[1],line[1]-line[0])-1)