fin=open("photo.in")
fout=open("photo.out","w")
n=int(fin.readline().strip())
ref=[i for i in range(1,n+1)]
arr=list(map(int,fin.readline().strip().split()))
test=arr[0]
for i in range(1,test):
    if test%2==0 and i==test//2:
        continue
    check=[i]
    curr=i
    for j in arr:
        check.append(j-curr)
        curr=j-curr
    if sorted(check)==ref:
        for a in range(n):
            fout.write(str(check[a]))
            if a==n-1:
                fout.write("\n")
            else:
                fout.write(" ")
        break
