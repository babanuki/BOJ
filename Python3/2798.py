import sys

read=sys.stdin.readline

n, m=map(int, read().split())

ans=0

g=list(map(int, read().split()))

for i in range(0, n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            now=g[i]+g[j]+g[k]
            if ans<now and now<=m:
                ans=now

print(ans)
