alphabet=input()
word=input()
(countword,res,countalpha)=(0,1,0)
while countword<len(word):
    if alphabet[countalpha]==word[countword]:
        countword+=1
    countalpha+=1
    if countalpha==26:
        countalpha=0
        res+=1
print(res)
    
