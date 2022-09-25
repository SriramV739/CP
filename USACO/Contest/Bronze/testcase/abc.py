fin=input()
fin=fin.split()
nums=[]
for i in fin:
    nums.append(int(i))
nums.sort()
res=""
res+=str(nums[0])
res+=" "
res+=str(nums[1])
res+=" "
res+=str(nums[-1]-nums[0]-nums[1])
print(res)