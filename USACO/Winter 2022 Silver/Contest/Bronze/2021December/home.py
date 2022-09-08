def run():
    t=int(input().strip())
    out=[]
    for a in range(t):
        n,k=map(int,input().strip().split())
        n-=1
        arr=[]
        count=0
        for i in range(n+1):
            arr.append(list(x for x in input().strip()))
        if arr[0][0]=="H" or arr[-1][-1]=="H":
            out.append(0)
            continue
        test=True
        for i in arr:
            if i.count("H")==len(i):
                out.append(0)
                test=False
                break
        if not test:
            continue
        
        
        total=[]
        total.append([])
        if k>=1:
            for i in range(n):
                total[-1].append("D")
            for i in range(n):
                total[-1].append("R")
        if k>=2:
            for d in range(1,n):
                total.append([])
                for i in range(d):
                    total[-1].append("D")
                for i in range(n):
                    total[-1].append("R")
                for i in range(n-d):
                    total[-1].append("D")
        if k>=3:
            for d in range(1,n):
                for r in range(1,n):
                    total.append([])
                    for i in range(d):
                        total[-1].append("D")
                    for i in range(r):
                        total[-1].append("R")
                    for i in range(n-d):
                        total[-1].append("D")
                    for i in range(n-r):
                        total[-1].append("R")
        test=True
        for i in arr:
            for j in i:
                if j=="H":
                    test=False
        if test:
            out.append(len(total)*2)
            continue
        for i in total:
            dup=[]
            for j in i:
                if j=="D":
                    dup.append("R")
                else:
                    dup.append("D")
            pos=[0,0]
            test=True
            for x in i:
                if arr[pos[0]][pos[1]]=="H":
                    test=False
                    break
                if x=="D":
                    pos[0]+=1
                else:
                    pos[1]+=1
            if arr[pos[0]][pos[1]]=="H":
                test=False
            if test:
                count+=1
            pos=[0,0]
            test=True
            for x in dup:
                if arr[pos[0]][pos[1]]=="H":
                    test=False
                    break
                if x=="D":
                    pos[0]+=1
                else:
                    pos[1]+=1
            if arr[pos[0]][pos[1]]=="H":
                test=False
            if test:
                count+=1
        out.append(count)
    for i in out:
        print(i)
run()