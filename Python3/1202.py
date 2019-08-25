import sys
import queue
read=sys.stdin.readline

n, k=read().split()
n=int(n)
k=int(k)

ans=0

pq=queue.PriorityQueue()

g=[]

for i in range(n):
    m, v=read().split()
    m=int(m)
    v=int(v)

    g.append((m, -v))

for i in range(k):
    g.append((int(read()), 1))

g.sort()

for i in g:
    if i[1] is 1:
        if not(pq.empty()):
            ans+=pq.get()
    else:
        pq.put(i[1])

print(-ans)
