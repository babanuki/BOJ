p=[]

def Find(a):
    if a==p[a]:
        return a
    else:
        p[a]=Find(p[a])
        return p[a]

def Union(a, b):
    p[Find(a)]=Find(b)

g=[]
ans=0
N=int(input())
M=int(input())

for i in range(0, N+1):
    p.append(i)

for i in range(0, M):
    s=input()
    s, e, w=s.split()
    s=int(s)
    e=int(e)
    w=int(w)
    g.append([w,s,e])

g.sort()

for i in range(0, len(g)):
    if Find(g[i][1])!=Find(g[i][2]):
        Union(g[i][1], g[i][2])
        ans+=g[i][0]

print(ans)
