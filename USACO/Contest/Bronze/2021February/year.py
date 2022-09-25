n=int(input())
dict1={"Bessie":[0,"Ox"]}
year=["Ox","Tiger","Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"]
year1=list(reversed(year))
for i in range(n):
    line=input()
    line=line.split()
    if i==0:
        if line[3]=="previous":
            if line[4]=="Ox":
                dict1[line[0]]=[-12,"Ox"]
            else:
                dict1[line[0]]=[-(year1.index(line[4])+1),line[4]]
        else:
            if line[4]=="Ox":
                dict1[line[0]]=[12,"Ox"]
            else:
                dict1[line[0]]=[year.index(line[4]),line[4]]
    else:
        if line[3]=="previous":
            if year.index(dict1[line[-1]][1])==year.index(line[4]):
                dict1[line[0]]=[dict1[line[-1]][0]-12,line[4]]
            elif year.index(dict1[line[-1]][1])>year.index(line[4]):
                dict1[line[0]]=[year.index(line[4])-year.index(dict1[line[-1]][1])+dict1[line[-1]][0],line[4]]
            else:
                dict1[line[0]]=[dict1[line[-1]][0]-year.index(dict1[line[-1]][1])-year1.index(line[4])-1,line[4]]
        else:
            if line[4]==dict1[line[-1]][1]:
                dict1[line[0]]=[dict1[line[-1]][0]+12,line[4]]
            elif line[4] in year[year.index(dict1[line[-1]][1]):]:
                dict1[line[0]]=[year.index(line[4])-year.index(dict1[line[-1]][1])+dict1[line[-1]][0],line[4]]
            else:
                dict1[line[0]]=[len(year)-year.index(dict1[line[-1]][1])+year.index(line[4])+dict1[line[-1]][0],line[4]]
print(abs(int(dict1["Elsie"][0])))
