n=int(input().strip())
s=input().strip()
count=0
for i in range(len(s)-2):
    h=0
    g=0
    for j in range(i,len(s)):
        if s[j]=="H":
            h+=1
        else:
            g+=1
        if j>=i+2:
            if h==1 or g==1:
                count+=1
            if h>=2 and g>=2:
                break

print(count)