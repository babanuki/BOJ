import copy

s=input()
N, M=s.split()
N=int(N)
M=int(M)
g=[]
canMove=[(0,1),(1,0),(0,-1),(-1,0)]
l=[]
chk=[]
m=0

for i in range(0, N):
    s=input()
    g.append(s)

for i in range(0, N):
    chk.append([])
    for j in range(0, M):
        chk[i].append(0)

chk[0][0]=1
l.append([0, 0, 1])

while True:
         X=l[0][1]
         Y=l[0][0]
         m=l[0][2]
         if X==M-1 and Y==N-1:
             break
         for k in range(0, 4):
             nowX=X+canMove[k][0]
             nowY=Y+canMove[k][1]
             if nowY>N-1 or nowY<0 or nowX>M-1 or nowX<0:
                 continue
             if g[nowY][nowX]=='1' and chk[nowY][nowX]!=1:
                chk[nowY][nowX]=1
                l.append([nowY, nowX, m+1])
         del l[0]

print(m)
