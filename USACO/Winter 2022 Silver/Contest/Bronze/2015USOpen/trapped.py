fin=open("trapped.in")
fout=open("trapped.out","w")
arr=[]
for i in range(int(fin.readline().strip())):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
arr.sort(key=lambda x:x[1])
if arr[-1][1]-arr[0][1]<=arr[0][0] and arr[-1][1]-arr[0][1]<=arr[-1][0]:
    fout.write(str(arr[-1][1]-arr[0][1]))
    fout.write("\n")
else:
    area=0
    for i in range(len(arr)-1):
        start=i
        end=i+1
        while True:
            left=True
            right=True
            dist=arr[end][1]-arr[start][1]
            if dist>arr[end][0]:
                end+=1
                right=False
            if dist>arr[start][0]:
                start-=1
                left=False
            if start==-1 or end==len(arr):
                break
            if right and left:
                area+=arr[i+1][1]-arr[i][1]
                break
            

    fout.write(str(area))
    fout.write("\n")
