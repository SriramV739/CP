n=int(input())
dict1={}
res=0
final=[]
for i in range(n):
    s=input().strip()
    x=int(s.split()[0])
    y=int(s.split()[1])
    count=0
    if str(x+1)+" " +str(y) in dict1:
        count+=1
        dict1[str(x+1)+" " +str(y)]+=1
        if dict1[str(x+1)+" " +str(y)]==4:
            res-=1
        if dict1[str(x+1)+" " +str(y)]==3:
            res+=1
    if str(x-1)+" " +str(y) in dict1:
        count+=1
        dict1[str(x-1)+" " +str(y)]+=1
        if dict1[str(x-1)+" " +str(y)]==4:
            res-=1
        if dict1[str(x-1)+" " +str(y)]==3:
            res+=1
    
    if str(x)+" " +str(y+1) in dict1:
        dict1[str(x)+" " +str(y+1)]+=1
        if dict1[str(x)+" " +str(y+1)]==4:
            res-=1
        if dict1[str(x)+" " +str(y+1)]==3:
            res+=1
        count+=1
    if str(x)+" " +str(y-1) in dict1:
        dict1[str(x)+" " +str(y-1)]+=1
        if dict1[str(x)+" " +str(y-1)]==4:
            res-=1
        if dict1[str(x)+" " +str(y-1)]==3:
            res+=1
        count+=1
    if count==3:
        res+=1
    dict1[str(x)+" " +str(y)]=count
    print(res)
