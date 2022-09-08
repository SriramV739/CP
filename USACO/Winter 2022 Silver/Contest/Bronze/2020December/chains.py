n=int(input().strip())
arr=list(int(x) for x in input().strip().split())
count=0
for i in range(len(arr)):
    for j in range(len(arr)+1):
        if i<j:
            if sum(arr[i:j])/len(arr[i:j]) in arr[i:j]:
                count+=1
print(count)