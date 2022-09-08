fin=open("traffic.in")
fout=open("traffic.out","w")
n=int(fin.readline().strip())
arr=[]

def update(arr1,arr2):
    return([max(arr1[0],arr2[0]),min(arr1[1],arr2[1])])

for i in range(n):
    arr.append(fin.readline().strip().split())
    arr[-1][1]=int(arr[-1][1])
    arr[-1][2]=int(arr[-1][2])

#first none
first=0
for i in range(len(arr)):
    if arr[i][0]!="on" and arr[i][0]!="off":
        first=i
        break
    

#last none
last=0
for i in range(len(arr)-1,-1,-1):
    if arr[i][0]!="on" and arr[i][0]!="off":
        last=i
        break



#backward
curr=[]
for i in range(last,-1,-1):
    if curr==[]:
        curr=arr[i][1:]
    
    elif arr[i][0]=="none":
        curr=update(curr,arr[i][1:])
    elif arr[i][0]=="off":
        curr[0]+=arr[i][1]
        curr[1]+=arr[i][2]
    
    else:
        curr[0]-=arr[i][2]
        curr[1]-=arr[i][1]
    #print(curr)
    

fout.write(str(curr[0])+" "+str(curr[1]))
fout.write("\n")


#forward
curr=[]
for i in range(first,len(arr)):
    if curr==[]:
        curr=arr[i][1:]
    
    elif arr[i][0]=="none":
        curr=update(curr,arr[i][1:])
    elif arr[i][0]=="on":
        curr[0]+=arr[i][1]
        curr[1]+=arr[i][2]
    
    else:
        curr[0]-=arr[i][2]
        curr[1]-=arr[i][1]
    
fout.write(str(curr[0])+" "+str(curr[1]))
fout.write("\n")









