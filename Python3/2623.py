import sys
read=sys.stdin.readline

def topologicalSort():
    global root, g, N, M, ans
    for i in range(1, N+1):
        if indgr[i]==0:
            root.append(i)

    for i in range(N):
        if len(root)==0:
            print(0)
            return
        x=root[0]
        del root[0]
        ans.append(x)
        for j in g[x]:
            indgr[j]-=1
            if indgr[j]==0:
                root.append(j)


N, M=list(map(int, read().split()))
g=[]
indgr=[0]*(N+1)

for i in range(N+1):
    g.append([])

for i in range(M):
    l=list(map(int, read().split()))
    for i in range(1, len(l)-1):
        g[l[i]].append(l[i+1])
        indgr[l[i+1]]+=1

root=[]
ans=[]

topologicalSort()

for i in ans:
    print(i)
