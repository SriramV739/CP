fin=open("socdist2.in")
fout=open("socdist2.out","w")
arr=[]
for i in range(int(fin.readline().strip())):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
arr.sort(key=lambda x: x[0])
r=[]
for i in range(len(arr)):
    if arr[i][1]==0:
        if i!=0:
            if arr[i-1][1]==1:
                r.append(abs(arr[i][0]-arr[i-1][0]))
        if i!=len(arr)-1:
            if arr[i+1][1]==1:
                r.append(abs(arr[i][0]-arr[i+1][0]))

if len(r)==0:
    fout.write("1")
    fout.write("\n")
else:
    r=min(r)
    count=1
    for i in range(len(arr)-1):
        if arr[i][1]==1:
            if arr[i+1][1]==1:
                if arr[i+1][0]-arr[i][0]>=r:
                    count+=1
        else:
            if arr[i+1][1]==1:
                count+=1
fout.write(str(count))
fout.write("\n")
