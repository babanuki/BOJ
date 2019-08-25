import sys
read=sys.stdin.readline

N, P=map(int, read().split())
W, L, G=map(int, read().split())

g={}

flag=False
pt=0

for i in range(P):
    l=read().split()
    g[l[0]]=l[1]

for i in range(N):
    player=input()
    if g.get(player)=='W':
        pt+=W
    else:
        pt-=L
        if pt<0:
            pt=0

    if pt>=G:
        flag=True

if flag:
    print("I AM NOT IRONMAN!!")
else:
    print("I AM IRONMAN!!")
