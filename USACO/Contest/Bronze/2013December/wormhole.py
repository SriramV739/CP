import itertools
fin=open("wormhole.in")
fout=open("wormhole.out","w")
arr=list(list(int(x) for x in fin.readline().strip().split()) for i in range(int(fin.readline().strip())))
arr1=list(x for x in range(len(arr)))
print(arr)
