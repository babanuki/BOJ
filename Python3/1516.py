import sys
read=sys.stdin.readline

def topologicalSort():
    global root, g, N, indgr, cost, result
    for i in range(1, N+1):
        if indgr[i]==0:
            result[i]=cost[i]
            root.append(i)
    
    for i in range(N):
        x=root[0]
        del root[0]
        for j in g[x]:
            indgr[j]-=1
            if indgr[j]==0:
                root.append(j)
            result[j]=max(result[j], result[x]+cost[j])


N=int(read())
g=[]
indgr=[0]*(N+1)
cost=[0]
result=[0]*(N+1)

for i in range(N+1):
    g.append([])

for i in range(1, N+1):
    l=list(map(int, read().split()))
    cost.append(l[0])
    indgr[i]=len(l)-2
    for j in range(1, len(l)-1):
        g[l[j]].append(i)

root=[]

topologicalSort()

for i in range(1, N+1):
    print(result[i])
