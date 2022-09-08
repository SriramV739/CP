fin=open("billboard.in")
fout=open("billboard.out",'w')
def area(arr):
    return((arr[3]-arr[1])*(arr[2]-arr[0]))

arr=[]
for i in range(3):
    arr.append(list(int(x) for x in fin.readline().split()))
(e,f,g,h)=(arr[-1][0],arr[-1][1],arr[-1][2],arr[-1][3])

count=0

def intersection(a,b):
    return((min(a[2],b[2])-max(a[0],b[0]))*(min(a[3],b[3])-max(a[1],b[1])))


for i in range(2):
    (a,b,c,d)=(arr[i][0],arr[i][1],arr[i][2],arr[i][3])
    count+=area(arr[i])
    if f<d and e<c and b<h and a<g:
        count-=(intersection(arr[i],arr[-1]))

fout.write(str(count))
fout.write("\n")