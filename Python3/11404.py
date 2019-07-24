import copy

def floyd_warshall(g, n):
    for k in range(0, n):
        for i in range(0, n):
            for j in range(0, n):
                if g[i][j]>g[i][k]+g[k][j]:
                    g[i][j]=g[i][k]+g[k][j]
    return g

g=[]

N=int(input())
M=int(input())

for i in range(0, N):
    g.append([])
    for j in range(0, N):
        if i==j:
            g[i].append(0)
        else:
            g[i].append(240000)

for i in range(0, M):
    s=input()
    l=s.split()
    a, b, c=l
    a=int(a)
    b=int(b)
    c=int(c)
    if c<g[a-1][b-1]:
        g[a-1][b-1]=c
        
G=floyd_warshall(copy.deepcopy(g), N)

for i in range(0, N):
    for j in range(0, N):
        if G[i][j]==240000:
            G[i][j]=0

for i in range(0, N):
    for j in range(0, N):
        print(str(G[i][j]), end=' ')
    print()
