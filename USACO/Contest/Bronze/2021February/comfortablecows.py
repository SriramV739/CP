n=int(input())
dict1={}
comfortable=[]
def checkComfort(dict1,x,y,comfortable):
    res=0
    count=0
    try:
        if dict1[x-1][y]:
            count=0
            try:
                if dict1[x-1][y-1]:
                    count+=1
            except:
                pass
            try:
                if dict1[x-2][y]:
                    count+=1
            except:
                pass
            try:
                if dict1[x-1][y+1]:
                    count+=1
            except:
                pass
    except:
        pass
    if count==3:
        if [x-1,y] in comfortable:
            comfortable.remove([x-1,y])
    else: 
        if count==2:
            res+=1
            comfortable.append([x-1,y])
        count=0
 
    try:
        if dict1[x+1][y]:
            count=0
            try:
                if dict1[x+2][y]:
                    count+=1
            except:
                pass
            try:
                if dict1[x+1][y-1]:
                    count+=1
            except:
                pass
            try:
                if dict1[x+1][y+1]:
                    count+=1
            except:
                pass
    except:
        pass
    if count==3:
        if [x+1,y] in comfortable:
                comfortable.remove([x+1,y])
    else:    
        if count==2:
            res+=1
            comfortable.append([x+1,y])
    count=0
    try:
        if dict1[x][y-1]:
            count=0
            try:
                if dict1[x-1][y-1]:
                    count+=1
            except:
                pass
            try:
                if dict1[x][y-2]:
                    count+=1
            except:
                pass
            try:
                if dict1[x+1][y-1]:
                    count+=1
            except:
                pass
    except:
        pass
    if count==3:
        if [x,y-1] in comfortable:
                comfortable.remove([x,y-1])
    if count==2:
        res+=1
        comfortable.append([x,y-1])
    count=0
    try:
        if dict1[x][y+1]:
            count=0
            try:
                if dict1[x][y+2]:
                    count+=1
            except:
                pass
            try:
                if dict1[x+1][y+1]:
                    count+=1
            except:
                pass
            try:
                if dict1[x-1][y+1]:
                    count+=1
            except:
                pass
    except:
        pass
    if count==3:
        if [x,y+1] in comfortable:
                comfortable.remove([x,y+1])
    if count==2:
        res+=1
        comfortable.append([x,y+1])
    count=0
    try:
        if dict1[x+1][y]:
            count+=1
    except:
        pass
    try:
        if dict1[x-1][y]:
            count+=1
    except:
        pass
    try: 
        if dict1[x][y-1]:
            count+=1
    except:
        pass
    try:
        if dict1[x][y+1]:
            count+=1
    except:
        pass

    if count==4:
        if [x,y] in comfortable:
            comfortable.remove([x,y])
    if count==3:
        comfortable.append([x,y])

    return(len(comfortable))
 



final=[]
for i in range(n):
    line=input().strip().split()
    x=int(line[0])
    y=int(line[1])
    if y not in dict1:
        dict1[y]=[]
    if len(dict1[y])<x+1:
        for j in range(x-len(dict1[y])+1):
            dict1[y].append(False)

    
    dict1[y][x]=True
    print((checkComfort(dict1,y,x,comfortable)))


'''for i in final:
    print(i)






'''