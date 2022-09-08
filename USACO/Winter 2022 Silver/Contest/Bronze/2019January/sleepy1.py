fin=open("sleepy.in")
fout=open("sleepy.out","w")
n=int(fin.readline().strip())
arr=list(int(x) for x in fin.readline().strip().split())
res=1
for i in range(len(arr)-1,0,-1):
    if arr[i]>arr[i-1]:
        res+=1
    else:
        break
fout.write(str(n-res))
fout.write("\n")