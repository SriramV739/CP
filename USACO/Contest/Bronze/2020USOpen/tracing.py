fin=open("tracing.in")
fout=open("tracing.out","w")
line=fin.readline().strip().split()
s=fin.readline().split()
sick=[]
for i in s:
    if i=="0":
        sick.append(False)
    else:
        sick.append(True)

arr=[]
k=[0,-1]
for i in range(int(line[1])):
    arr.append(list(int(x) for x in fin.readline().strip().split()))
arr.sort(key=lambda x: x[0])
for i in range(len(sick)):
    if sick[i]:
        test=[]
        for j in sick:
            test.append([False,0])
        test[i][0]=True
        for i in arr:
            a=test[i[1]]
            b=test[i[2]]
            if a[0] and not b[0]:
                if sick[i[1]]:
                    

    