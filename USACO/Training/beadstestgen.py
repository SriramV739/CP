import random
l=["r","w","b"]

for i in range(10):
    res=""
    for i in range(10):
        res+=(random.choice(l))
    print(res)

