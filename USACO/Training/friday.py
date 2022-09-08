"""
ID: your_id_here
LANG: PYTHON3
TASK: friday
"""
fin=open("friday.in","r")
fout=open("friday.out","w")
n=int(fin.readline())
days=[0,0,0,0,0,0,0]
monthday=[31,28,31,30,31,30,31,31,30,31,30,31]
year=1899
daynum=0
while year<1899+n:
    month=0
    year+=1
    while month<12:
        count=0
        month+=1
        if year==2000 and month==2:
            x=29
        elif year%4==0 and year%100!=0 and month==2:
            x=29
        else:
            x=monthday[month-1]
        while count<x:
            count+=1
            daynum+=1
            if daynum==8:
                daynum=1
            if count==13:
                days[daynum-1]+=1
fout.write(str(days[5]))
fout.write(" ")
fout.write(str(days[6]))
fout.write(" ")
for i in range(5):
    if i==4:
        fout.write(str(days[4]))
        break
    else:
        fout.write(str(days[i]))
        fout.write(" ")
fout.write("\n")
