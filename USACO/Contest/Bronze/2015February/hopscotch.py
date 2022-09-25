fin=open("hopscotch.in")
fout=open("hopscotch.out","w")
r,c=map(int,fin.readline().strip().split())
arr=[]
for i in range(r):
    line=fin.readline().strip()
    arr.append([])
    for j in line:
        arr[-1].append(j)
count=0
def rec(curr,color):
    global arr
    global count
    if curr==[len(arr)-1,len(arr[0])-1]:
        count+=1
        return()
    elif curr==[len(arr)-2,len(arr[0])-1]:
        return()
    elif curr==[len(arr)-1,len(arr[0])-2]:
        return()
    else:
        for i in range(curr[0]+1,len(arr)):
            for j in range(curr[1]+1,len(arr[0])):
                if arr[i][j]!=color:
                    if color=="R":
                        rec([i,j],"B")
                    else:
                        rec([i,j],"R")

rec([0,0],arr[0][0])
fout.write(str(count))
fout.write("\n")