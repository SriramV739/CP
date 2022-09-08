from typing import Counter


fin=open("meeting.in")
fout=open("meeting.out","w")
n,m=map(int,fin.readline().strip().split())
g={}
dict1={}
for j in range(m):
    line=list(int(x) for x in fin.readline().strip().split())
    if line[0] in g:
        g[line[0]].append(line[1])
        dict1[line[0]].append(line[1:])
    else:
        g[line[0]]=[line[1]]
        dict1[line[0]]=[line[1:]]
paths=[]
def traverse(start):
    if start==1:
        (count1,count2)=(0,0)
    for i in g[start]:
        if i[0]==n:
            paths.append(count1)
            paths.append(count2)
            return()
        elif i[0] not in g:
            return()
        else:
            (count1,count2)=(i[1],i[2])
total=[]

# Python3 program to print all paths of
# source to destination in given graph
from typing import List
from collections import deque
 
# Utility function for printing
# the found path in graph
def printpath(path: List[int]) -> None:
     
    total.append(path)         
 
# Utility function to check if current
# vertex is already present in path
def isNotVisited(x: int, path: List[int]) -> int:
 
    size = len(path)
    for i in range(size):
        if (path[i] == x):
            return 0
             
    return 1
 
# Utility function for finding paths in graph
# from source to destination
def findpaths(g: List[List[int]], src: int,
              dst: int) -> None:
                   
    # Create a queue which stores
    # the paths
    q = deque()
 
    # Path vector to store the current path
    path = []
    path.append(src)
    q.append(path.copy())
     
    while q:
        path = q.popleft()
        last = path[len(path) - 1]
 
        # If last vertex is the desired destination
        # then print the path
        if (last == dst):
            printpath(path)
 
        # Traverse to all the nodes connected to
        # current vertex and push new path to queue
        if last in g:
            for i in range(len(g[last])):
                if (isNotVisited(g[last][i], path)):
                    newpath = path.copy()
                    newpath.append(g[last][i])
                    q.append(newpath)
    
# Driver code
    
# Number of vertices
v = m
#g = [[] for _ in range(4)]

# Construct a gra
src = 1
dst = n


# Function for finding the paths
findpaths(g, src, dst)

coste=[]
costb=[]
for i in total:
    counte=0
    countb=0
    for j in range(1,len(i)):
        prev=i[j-1]
        curr=i[j]
        index=g[prev].index(curr)
        counte+=(dict1[prev][index][1])
        countb+=(dict1[prev][index][2])
    coste.append(counte)
    costb.append(countb)
coste.sort()
test=False
for i in coste:
    if i in costb:
        fout.write(str(i))
        test=True
        exit()

fout.write("IMPOSSIBLE")
fout.write("\n")
        