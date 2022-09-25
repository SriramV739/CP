n=input()
cow=input()
height=input()
cow=cow.split()
cowfinal=[]
for i in cow:
    cowfinal.append(int(i))
cowfinal.sort(reverse=True)
heightfinal=[]
height=height.split()
for i in height:
    heightfinal.append(int(i))
count=0
subtract=0
nums=[]
for i in cowfinal:
    for j in heightfinal:
        if j>=i:
            count+=1
    nums.append(count-subtract)
    subtract+=1
    count=0
res=1
for i in nums:
    if i!=0:
        res*=i
print(res)