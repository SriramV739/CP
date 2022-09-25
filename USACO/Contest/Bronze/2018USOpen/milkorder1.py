fin=open("milkorder.in")
fout=open("milkorder.out","w")
line=list(int(x) for x in fin.readline().strip().split())
test=[]
for i in range(line[0]):
    test.append(-1)
stop=False
h=list(int(x) for x in fin.readline().strip().split())
for i in range(line[2]):
    l=list(int(x) for x in fin.readline().strip().split())
    test[l[-1]]=l[0]
    if l[0]==1:
        fout.write(str(l[1]))
        fout.write("\n")
        stop=True
        break

if not stop:
    for i in range(len(test)):
        if test[i]==-1:
            arr=test.copy()
            arr[i]=1
            curr=0
            start=0
            for i in h:
                if i in arr:

        check=[]
        for i in arr:
            if i in h:
                check.append(i)
        if check==h:
            fout.write(str(arr.index(1)))
            

    