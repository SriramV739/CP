import random
fout=open("milk2.in","r")
fout.write("4")
fout.write("\n")
for i in range(4):
    n=(random.randint(5000))
    fout.write(str(n%100))
    fout.write(" ")
    fout.write(str(random.randint(n,10000)%100))

