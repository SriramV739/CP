n=int(input())
for j in range(n):
    s=input().strip()
    (nindex,sindex,eindex,windex,nmax,smax,emax,wmax,hcount,vcount)=(0,0,0,0,0,0,0,0,0,0)
    for i in range(len(s)):
        if s[i]=="W":
            hcount-=1
            if hcount<=wmax and hcount<=0:
                wmax=hcount
                windex=i
        elif s[i]=="N":
            vcount+=1
            if vcount>=nmax and vcount>=0:
                nmax=vcount
                
                nindex=i
        elif s[i]=="S":
            vcount-=1
            if vcount<=smax and vcount<=0:
                smax=vcount
                
                sindex=i
        elif s[i]=="E":
            hcount+=1
            if hcount>=emax and hcount>=0:
                emax=hcount

                eindex=i
    #print(nindex,windex,sindex)
    dict1={windex:"W", nindex:"N", eindex:"E", sindex:"S"}
    #print(dict1)
    res=""
    for i in sorted(list(dict1.keys())):
        res+=dict1[i]
    #print(res)
    if res=="SWNE" or res=="WNES" or res=="NESW" or res=="ESWN":
        print("CW")
    else:
        print("CCW")
