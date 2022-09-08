import random
for i in range(5):
    a=random.randint(0,4)
    b=random.randint(0,4)
    print(str(min(a,b))+" ",str(max(a,b)))
