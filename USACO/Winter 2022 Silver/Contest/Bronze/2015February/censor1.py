fin=open("censor.in")
fout=open("censor.out","w")
f=fin.readline().strip()
s=fin.readline().strip()
arr=[]
censor=[]
for i in f:
    arr.append(i)
for i in s:
    censor.append(i)

stack=[]

i=0
'''while i<len(arr):
    if arr[i]==censor[0]:
        stack.append(0)
    
    elif len(stack)!=0:
        if arr[i]==censor[stack[-1]+1]:
            stack[-1]+=1
            if stack[-1]==len(censor)-1:
                del stack[-1]
                del arr[i-len(censor)+1:i+1]
                i-=len(censor)
        else:
            stack=[]
    else:
        stack=[]
    i+=1'''




while i<len(arr):
    if len(stack)==0:
        if arr[i]==censor[0]:
            stack.append(0)
        i+=1
    else:


        if arr[i]==censor[stack[-1]+1]:
            stack[-1]+=1
            if stack[-1]==len(censor)-1:
                del stack[-1]
                del arr[i-len(censor)+1:i+1]
                i-=len(censor)            
            i+=1
        if arr[i]==censor[0]:
            stack.append(0)
            i+=1

        
        else:
            stack=[]
            i+=1



for i in arr:
    fout.write(i)
fout.write("\n")
    