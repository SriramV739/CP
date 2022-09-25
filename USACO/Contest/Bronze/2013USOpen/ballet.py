fin=open("ballet.in")
fout=open("ballet.out","w")
arr=[]
for i in range(int(fin.readline().strip())):
    arr.append(fin.readline().strip())
dict1={"RL":[0,0],"RR":[1,0],"FL":[0,1],"FR":[1,1]}
res=[[0,0],[0,1],[1,0],[1,1]]
dir=0
for i in arr:
    if i[-1]=="P":
        pos=dict1[i[:2]]
        for j in dict1:
            if j!=i[:2]:
                move=dict1[j]
                x=pos[0]-move[0]
                y=move[1]-pos[1]
                dict1[j]=[pos[0]+y,pos[1]+x]
        dir+=1
        dir%=4
    else:
        if i[-1]=="R":
            if dir==0:
                dict1[i[:2]][0]+=1
            elif dir==2:
                dict1[i[:2]][0]-=1
            elif dir==1:
                dict1[i[:2]][1]-=1
            else:
                dict1[i[:2]][1]+=1
        elif i[-1]=="F":
            if dir==0:
                dict1[i[:2]][1]+=1
            elif dir==2:
                dict1[i[:2]][1]-=1
            elif dir==1:
                dict1[i[:2]][0]+=1
            else:
                dict1[i[:2]][0]-=1
        elif i[-1]=="B":
            if dir==0:
                dict1[i[:2]][1]-=1
            elif dir==2:
                dict1[i[:2]][1]+=1
            elif dir==1:
                dict1[i[:2]][0]-=1
            else:
                dict1[i[:2]][0]+=1
        else:
            if dir==0:
                dict1[i[:2]][0]-=1
            elif dir==2:
                dict1[i[:2]][0]+=1
            elif dir==1:
                dict1[i[:2]][1]+=1
            else:
                dict1[i[:2]][1]-=1
    if len(list(set(list(str(x) for x in dict1.values()))))!=len(list(dict1.values())):
        fout.write(str(-1))
        fout.write("\n")
        exit()
    else:
        res+=(list(dict1.values()))
print(dict1)
left=min(list((i[0] for i in res)))
right=max(list((i[0] for i in res)))
top=max(list(i[1] for i in res))
down=min(list(i[1] for i in res))
print(left,right,top,down)
width=right-left+1
height=top-down+1
fout.write(str(width*height))
fout.write("\n")