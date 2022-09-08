"""
ID: your_id_here
LANG: PYTHON3
TASK: transform
"""


fin=open("transform.in","r")
fout=open("transform.out","w")
n=int(fin.readline())
trans1=[]
trans2=[]
for i in range(n):
    s=fin.readline().strip()
    trans1.append(s)
for i in range(n):
    s=fin.readline().strip()
    trans2.append(s)



def oneEighty(trans1,trans2,n):
  res=[]
  for i in range(n-1,-1,-1):
    line=trans1[i]
    s=""
    for j in range(n-1,-1,-1):
      s+=line[j]
    res.append(s)
  if res==trans2:
    return(True)
  else:
    return(False)
#------------------------------------------
def reflection(trans1,trans2,n,yesret):
  column1 = []
  for i in range(n):
    column1.append("")
  for i in range(n-1,-1,-1):
    for j in range(n):
      column1[j]+=(trans1[j][i])
  if yesret:
    return(column1)
  if column1==trans2:
    return True
  else:
    return False
#---------------------------------------
def combination(trans1,tran2,n):
  res=reflection(trans1,trans1,n,True)
  if ninety(res,trans2,n):
    return(True)
  elif oneEighty(res,trans2,n):
    return(True)
  elif twoSeventy(res,trans2,n):
    return(True)
  else:
    return(False)
#-----------------------------------------
def twoSeventy(trans1,trans2,n):
  column1 = []
  for i in range(n-1,-1,-1):
    s = ""
    for j in range(n):
      s += trans1[j][i]
    column1.append(s)
  if column1==trans2:
    return True
  else:
    return False

#----------------------------
def ninety(trans1,trans2,n):
  column=[]
  for i in range(n):
    column.append("")
  for i in range(n-1,-1,-1):
    line = trans1[i]
    for j in range(len(line)-1,-1,-1):
      s = line[j]
      column[j] += s
  if column==trans2:
    return True
  else:
    return False
#-----------------------------------  
while True:
  if ninety(trans1, trans2,n):
    fout.write("1")
    break
  elif oneEighty(trans1, trans2,n):
    fout.write("2")
    break
  elif twoSeventy(trans1, trans2,n):
    fout.write("3")
    break
  elif reflection(trans1, trans2,n,False):
    fout.write("4")
    break
  elif combination(trans1, trans2,n):
    fout.write("5")
    break
  elif trans1==trans2:
    fout.write("6")
    break
  else:
    fout.write("7")
    break
fout.write("\n")