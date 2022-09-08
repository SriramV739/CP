n=int(input().strip())
prev2=1
prev1=1
if n==1 or n==2:
    print(1)
else:
    for i in range(n-2):
        curr=prev2+prev1
        prev2=prev1
        prev1=curr

    print(curr)


