fin=open("relay.in")
fout=open("relay.out","w")
dict1={}
for i in range(int(fin.readline().strip())):
    dict1[i+1]=int(fin.readline().strip())
count=0
for i in dict1:
    reached={}
    curr=i
    while True:
        prev=curr
        curr=dict1[curr]
        if curr not in reached:
            reached[curr]=1
        else:
            count+=1
            break
        if curr==0:
            break
fout.write(str(len(dict1)-count))
fout.write("\n")