n=input()
id=(int(i) for i in input().strip().split())
(even,odd)=(0,0)
for i in id:
    if i%2==0:
        even+=1
    else:
        odd+=1
count=0
if even>odd:
    print((2*odd)+1)
else:
    count+=2*even
    odd-=even
    count+=2*(odd//3)
    if odd%3==2:
        count+=1
    elif odd%3==1:
        count-=1
    print(count)
