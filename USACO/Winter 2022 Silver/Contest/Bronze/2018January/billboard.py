fin=open("billboard.in")
fout=open("billboard.out","w")
a=list(int(x) for x in fin.readline().strip().split())
b=list(int(x) for x in fin.readline().strip().split())
(z,y,c,d)=(a[0],a[1],a[2],a[3])
(e,f,g,h)=(b[0],b[1],b[2],b[3])
owid=a[3]-a[1]
olen=a[2]-a[0]
print(a,b)
if f<d and e<c and y<h and z<g:
    length=(min(a[2],b[2])-max(a[0],b[0]))
    width=(min(a[3],b[3])-max(a[1],b[1]))
    print(width,length,owid,olen)
    if width>=owid:
        fout.write(str(max(0,olen-length)*owid))
    elif length>=olen:
        fout.write(str(max(0,owid-width)*olen))
    else:
        fout.write(str(olen*owid))
else:
    fout.write(str(olen*owid))
