n=int(input().strip())
for i in range(n):
    s=input().strip()
    count1=0
    count2=0
    finalcount=0
    if s[0]=="N" or s[0]=="S":
        finalcount=0
        for i in s:
            if i=="S":
                count1-=1
            elif i=="N":
                count1+=1
            elif i=="E":
                count2+=1
            else:
                count2-=1
            if count1==0 and count2!=0:
                finalcount=count2
        if s[0]=="N":
            if finalcount>0:
                print("CW")
            else:
                print("CCW")
        else:
            if finalcount>0:
                print("CW")
            else:
                print("CCW")


    else:
        finalcount=0
        for i in s:
            if i=="S":
                count1-=1
            elif i=="N":
                count1+=1
            elif i=="E":
                count2+=1
            else:
                count2-=1
            if count2==0 and count1!=0:
                finalcount=count1
        if s[0]=="W":
            if finalcount>0:
                print("CW")
            else:
                print("CCW")
        else:
            if finalcount>0:
                print("CW")
            else:
                print("CCW")
