n=input()
s=input()
s=s.split()
flower=[]
for i in s:
    flower.append(int(i))
all=[]
for i in range(len(flower)):
    for j in range(i+1,len(flower)):
        all.append(flower[i:j+1])
res=0
for i in range(len(flower)):
    all.append([flower[i]])
for i in all:
    if (sum(i)/len(i)) in i:
        res+=1
print(res) 