import sys
import math

read=sys.stdin.readline

ax, ay, bx, by, cx, cy=map(int, read().split())

ca=math.sqrt((ax-cx)**2+(ay-cy)**2)
ab=math.sqrt((bx-ax)**2+(by-ay)**2)
bc=math.sqrt((cx-bx)**2+(cy-by)**2)

m=min(ca+ab, ab+bc, bc+ca)
M=max(ca+ab, ab+bc, bc+ca)

if (ax-bx)*(ay-cy)==(ax-cx)*(ay-by):
    print(-1)
else:
    print(2*M-2*m)
