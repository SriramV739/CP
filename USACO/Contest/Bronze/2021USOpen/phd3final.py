line=list(int(x) for x in input().strip().split())
arr=[]
for i in range(line[0]):
    line=input().strip()
    arr.append([])
    for j in line:
        arr[-1].append(j)
grass={}

def encrypt(a):
    return(str(a[0])+"x"+str(a[1]))

def decrypt(s):
    return([int(s[:s.index("x")]),int(s[s.index("x")+1:])])
two={}

res=0
for i in range(len(arr)):
    for j in range(len(arr[i])):
        count=0
        if arr[i][j]=="G":
            neighbors=[]
            if i!=0:
                if arr[i-1][j]=="C":
                    count+=1
                    neighbors.append([i-1,j])
            if i!=len(arr)-1:
                if arr[i+1][j]=="C":
                    count+=1
                    neighbors.append([i+1,j])
            if j!=len(arr[i])-1:
                if arr[i][j+1]=="C":
                    count+=1
                    neighbors.append([i,j+1])
            if j!=0:
                if arr[i][j-1]=="C":
                    count+=1
                    neighbors.append([i,j-1])
            
            if count==2:
                if encrypt(neighbors) not in two and encrypt(list(reversed(neighbors))) not in two:
                    two[encrypt(neighbors)]=1
                    res+=1
            elif count==3 or count==4:
                res+=1

print(res)