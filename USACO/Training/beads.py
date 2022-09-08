"""
ID: your_id_here
LANG: PYTHON3
TASK: beads
"""
fin=open("beads.in","r")
fout=open("beads.out","w")
n=int(fin.readline())
beads=fin.readline()
nums=[]
for i in range(len(beads)):
    if beads[i]!="w":
        element=beads[i]
        break
count=0
wcount=0
res=True
for i in range(n):
    if beads.count("w")==n:
        fout.write(str(n))
        fout.write("\n")
        break
    if beads[i]==element:
        res=True
        count+=1
        wcount=0
    elif beads[i]=="w":
        res=True
        count+=1
        wcount+=1
    if beads[i]!=element and beads[i]!="w":
        res=False
        nums.append([count,wcount])
        count=1
        element=beads[i]
        wcount=0
        
    if i==n-1:       
        if res==False:
            count=1
        wcount=0
        res=False
        for j in range(n):
            if beads[j]==element:
                res=True
                count+=1
                wcount=0
            if beads[j]=="w":
                count+=1
                wcount+=1
            if beads[j]!=element and beads[j]!="w":
                break
        nums.append([count,wcount])


if len(nums)==1:
    if nums[0][0]>n:
        fout.write(str(n))
        fout.write("\n")
    else:
        fout.write(str(nums[0][0]))
        fout.write("\n")

if len(nums)>1:
    for i in range(len(nums)):
        if i==0:
            nums[0][1]=0
            switch=nums[0][1]
        else:
            switch1=nums[i][1]
            nums[i][1]=switch
            switch=switch1
    nums2=[]
    for i in range(len(nums)):
        if i==len(nums)-1:
            if res==True:
                nums2.append(nums[-1][0])
            else:
                nums2.append(nums[-1][0]+nums[0][0]-nums[-1][1])




        if i==0 and res==True:
            switch=nums[0][0]
            nums[0][0]=nums[-1][0]
        if i!=len(nums)-1:
            if nums[i+1][1]!=0:
                nums2.append(nums[i][0]+nums[i+1][0]+nums[i][1])
            else:
                nums2.append(nums[i][0]+nums[i][1]+nums[i+1][0])
        if i==0 and res==True:
            nums[0][0]=switch


    if max(nums2)>n:
        x=n
    else:
        x=max(nums2)
    
    fout.write(str(x))
    fout.write("\n")


