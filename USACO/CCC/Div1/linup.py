n=int(input().strip())
cond=[]
for i in range(n):
    line=input().strip().split()
    cond.append([line[0],line[-1]])
arr=["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
arr.sort()
import itertools
for i in itertools.permutations(arr):
    test=True
    for j in cond:
        if abs(i.index(j[0])-i.index(j[1]))!=1:
            test=False
            break
    if test:
        for j in i:
            print(j)
        break