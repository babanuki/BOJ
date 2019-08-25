import sys
read=sys.stdin.readline

N=int(input())
M=int(input())

Max=0

l=list(map(int, read().split()))

l.sort()

for i in range(M-1):
    Max=max(l[i+1]-l[i], Max)

ans=int((Max+1)/2)
Max=max(ans, l[0],  N-l[M-1])

print(Max)
