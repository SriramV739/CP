fin=open("square.in","r")
fout=open("square.out","w")
def area(arr):
    return((arr[3]-arr[1])*(arr[2]-arr[0]))


arr=[]
for i in range(2):
    arr.append(fin.readline().strip().split())
    for j in range(len(arr[-1])):
        arr[-1][j]=int(arr[-1][j])

rect=((([min(arr[0][0],arr[1][0]),min(arr[0][1],arr[1][1]),max(arr[0][2],arr[1][2]),max(arr[0][3],arr[1][3])])))
xdist=rect[2]-rect[0]
ydist=rect[3]-rect[1]
fout.write(str(max(xdist,ydist)**2))
fout.write("\n")