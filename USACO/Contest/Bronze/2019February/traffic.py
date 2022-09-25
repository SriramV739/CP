fin=open("traffic.in")
fout=open("traffic.out","w")
n=int(fin.readline().strip())
arr=[]
none=False

ref=[]





for i in range(n):
    line=fin.readline().strip().split()
    line[1]=int(line[1])
    line[2]=int(line[2])
    print(arr, line)
    ref.append(line)
    if line[0]=="none":
        if arr==[]:
            arr=line[1:]
        else:
            arr=[max(arr[0],line[1]),min(arr[1],line[2])]
        none=True
    elif line[0]=="on" and none:
        arr[0]+=line[1]
        arr[1]+=line[2]
    elif line[0]=="off" and none:
        arr[0]-=line[2]
        arr[1]-=line[1]
end=arr
arr=[]
none=False


for i in range(n-1,-1,-1):
    line=ref[i]
    if line[0]=="none":
        if arr==[]:
            arr=line[1:]
        else:
            arr=[max(arr[0],line[1]),min(arr[1],line[2])]
        none=True
    elif line[0]=="on" and none:
        arr[0]-=line[2]
        arr[1]-=line[1]
    

    elif line[0]=="off" and none:
        arr[0]+=line[1]
        arr[1]+=line[2]
    print(arr,line)
start=arr

fout.write(str(start[0]))
fout.write(" ")
fout.write((str(start[1])))
fout.write("\n")
fout.write(str(end[0]))
fout.write(" ")
fout.write(str(end[1]))
fout.write("\n")