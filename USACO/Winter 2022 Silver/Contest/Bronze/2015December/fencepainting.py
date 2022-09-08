fin=open("paint.in","r")
fout=open("paint.out","w")
fline=fin.readline().strip().split()
sline=fin.readline().strip().split()
start=[int(fline[0]),int(sline[0])]
end=[int(fline[1]),int(sline[1])]

if max(start)>min(end):
    fout.write(str((end[0]-start[0])+(end[1]-start[1])))
else:
    fout.write(str(max(end)-min(start)))
fout.write("\n")