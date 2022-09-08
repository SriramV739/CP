n=int(input())
for j in range(n):
    s=input().strip()
    sidecount=0
    upcount=0
    vertical=[]
    horizontal=[]
    for i in s:
        if i=="S":
            upcount-=1
            vertical.append(upcount)
        elif i=="N":
            upcount+=1
            vertical.append(upcount)
        elif i=="W":
            sidecount-=1
            horizontal.append(sidecount)
        elif i=="E":
            sidecount+=1
            horizontal.append(sidecount)
    if abs((max(vertical)))>abs((min(vertical))):
        v=max(vertical)
    elif abs((max(vertical)))==abs((min(vertical))):
        v=vertical[min(vertical.index(max(vertical)),vertical.index(min(vertical)))]
    else:
        v=min(vertical)
    if abs((max(horizontal)))>abs((min(horizontal))):   
        h=max(horizontal)
    elif abs((max(horizontal)))==abs((min(horizontal))):
        h=horizontal[min(horizontal.index(max(horizontal)),horizontal.index(min(horizontal)))]
    else:
        h=min(horizontal)
    #print(horizontal,vertical)
    #print(h,v)
    hindex=-1
    vindex=-1
    upcount=0
    sidecount=0
    for i in range(len(s)):
        if s[i]=="S":
            upcount-=1
            if upcount==v:
                if vindex==-1:  
                    vindex=i
        elif s[i]=="N":
            upcount+=1
            if upcount==v:
                if vindex==-1:  
                    vindex=i
        elif s[i]=="W":
            sidecount-=1
            if sidecount==h:
                if hindex==-1:
                    hindex=i
        elif s[i]=="E":
            sidecount+=1
            if sidecount==h:
                if hindex==-1:
                    hindex=i
    #print(hindex,vindex)
    if vindex>hindex:
        if v>0:
            y="N"
        else:
            y="S"
        if h>0:
            x="E"
        else:
            x="W"
    else:
        if v>0:
            x="N"
        else:
            x="S"
        if h>0:
            y="E"
        else:
            y="W"
    #print(x,y)
    if x=="S" and y=="W":
        print("CW")
    if x=="W" and y=="S":
        print("CCW")
    if x=="N" and y=="W":
        print("CCW")
    if x=="W" and y=="N":
        print("CW")
    if x=="S" and y=="E":
        print("CCW")
    if x=="E" and y=="S":
        print("CW")
    if x=="N" and y=="E":
        print("CW")
    if x=="E" and y=="N":
        print("CCW")
    