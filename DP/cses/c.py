x=list((int(i)) for i in input().strip().split())
counter=0
for a in range(1,x[0]-2):
    for b in range(1,x[0]-a-1):
        if x[0]-a-b>=1:
            c=x[0]-a-b
            for d in range(1,x[1]-2):
                for e in range(1,x[1]-d-1):
                    if x[1]-d-e>=1:
                        f=x[1]-d-e
                        for g in range(1,x[2]-2):
                                for h in range(1,x[2]-g-1):
                                    if x[2]-g-h>=1:
                                        i=x[0]-g-h
                                        if a+d+g==x[3] and b+e+h==x[4] and c+f+i==x[5]:
                                            print(a,b,c,d,e,f,g,h,i)
                                            counter+=1
print(counter)

