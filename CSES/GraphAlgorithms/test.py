def is_perfect_cube(n):
    c = int(n**(1/3.))
    return (c**3 == n) or ((c+1)**3 == n)
i=1
while True:
    if is_perfect_cube(i**3+2*(i**2)+11*i+10):
        print(i)
        break
    i+=1