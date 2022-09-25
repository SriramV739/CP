fin=open("baseball.in")
fout=open("baseball.out","w")
arr=sorted(list(int(fin.readline().strip()) for i in range(int(fin.readline().strip()))))
count=0
for i in range(1,len(arr)-1):
    for j in range(i):
        for k in range(i+1,len(arr)):
            if 2*(arr[i]-arr[j])<(arr[k]-arr[i]):
                break
            elif arr[i]-arr[j]<=arr[k]-arr[i]:
                count+=1

fout.write(str(count))
fout.write("\n")