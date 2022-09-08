fin=open("milkorder.in")
fout=open("milkorder.out","w")
fline=list(int(x) for x in fin.readline().strip().split())
arr=list(False for i in range(fline[0]))

h=list(int(x) for x in fin.readline().strip().split())
test=True
for i in range(fline[-1]):
    line=list(int(x) for x in fin.readline().strip().split())
    arr[line[1]-1]=line[0]
    if line[0]==1:
        fout.write(str(line[1]))
        fout.write("\n")
        test=False

if test:
    res=False
    for j in range(len(arr)):
        if arr[j]==False:
            arr1=arr.copy()
            arr1[j]=1
            for i in range(len(h)):
                print(h[i])
                if i==0:
                    if h[i] not in arr1:
                        arr1[arr1.index(False)]=h[i]
                else:
                    if h[i] not in arr1:
                        arr1[arr1.index(h[i-1])+arr1[arr1.index(h[i-1]):].index(False)]=h[i]
                    else:
                        if arr1.index(h[i])<arr1.index(h[i-1]):
                            break
                if i==len(h)-1:
                    print(arr1,j)
                    fout.write(str(j+1))
                    fout.write("\n")
                    res=True
                    break
            if res:
                break