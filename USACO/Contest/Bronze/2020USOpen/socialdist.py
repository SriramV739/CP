fin=open("socdist1.in","r")
fout=open("socdist1.out","w")
n=int(fin.readline())
s=str(fin.readline())
nums=[]
count=0
test=False
start=False
end=False
for i in range(len(s)):
    if s[i].isnumeric():
        if i!=0 and int(s[i])==1:
            nums.append(count)
            count=0
        if int(s[i])==0:
            count+=1
            if i==0:
                start=True
if count!=0:
    end=True
    nums.append(count)
for i in range(2):
    if (nums.index(max(nums))==0 and start) or (nums.index(max(nums))==len(nums)-1 and end):
        nums[nums.index(max(nums))]-=1
    else:
        if max(nums)%2==0:
            x=max(nums)    
            nums[nums.index(max(nums))]=max(nums)//2
            nums.append(x//2-1)
        else:
            x=max(nums)
            nums[nums.index(max(nums))]=max(nums)//2
            nums.append(x//2)
fout.write(str(min(nums)+1))
print(nums)
fout.write("\n")