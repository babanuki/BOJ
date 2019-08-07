import sys

read=sys.stdin.readline

def func(now):
    global g, n, k

    for i in range(0, n):
        if i==now:
            continue
        if g[i][1]>g[now][1]:
            continue
        if g[i][1]<g[now][1]:
            g[now][4]-=1
            continue
        if g[i][2]>g[now][2]:
            continue
        if g[i][2]<g[now][2]:
            g[now][4]-=1
            continue
        if g[i][3]>g[now][3]:
            continue
        if g[i][3]<=g[now][3]:
            g[now][4]-=1

    if g[now][0]==k:
        print(g[now][4])
        return
        

n, k=map(int, read().split())

g=list()

for i in range(0, n):
    l=list(map(int, read().split()))
    l.append(n)
    g.append(l)

for i in range(0, n):
           func(i)

