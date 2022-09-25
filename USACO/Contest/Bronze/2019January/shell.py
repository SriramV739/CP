fin=open("shell.in","r")
fout=open("shell.out","w")
n=int(fin.readline().strip())
pos=[0,1,2]
res=[0,0,0]
for i in range(n):
    arr=(fin.readline().strip().split())
    for j in range(len(arr)):
        arr[j]=int(arr[j])
    (pos[arr[0]-1],pos[arr[1]-1])=(pos[arr[1]-1],pos[arr[0]-1])
    res[pos[arr[2]-1]]+=1
fout.write(str(max(res)))
fout.write("\n")