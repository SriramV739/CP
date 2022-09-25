fin=open("cowqueue.in")
fout=open("cowqueue.out","w")
n=int(fin.readline().strip())
time=0
arr=[]
for i in range(n):
    arr.append(list(int(x) for x in fin.readline().strip().split()))

arr.sort(key=lambda x: x[0])
for line in arr:
    time=max(time,line[0])    
    time+=line[1]

fout.write(str(time))
fout.write("\n")