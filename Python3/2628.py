import sys
read=sys.stdin.readline

def func():
    global gy, gx, MX, MY

    for i in range(len(gx)-1):
        if gx[i+1]-gx[i]>MX:
            MX=gx[i+1]-gx[i]

    for i in range(len(gy)-1):
        if gy[i+1]-gy[i]>MY:
            MY=gy[i+1]-gy[i]

    return


gy=[]
gx=[]

MX, MY=0, 0

x, y=map(int, read().split())

m=int(input())

for i in range(m):
    a, b=map(int, read().split())
    if a is 0:
        gy.append(b)
    else:
        gx.append(b)

gy.append(0)
gy.append(y)
gx.append(0)
gx.append(x)

gy.sort()
gx.sort()

func()

print(MX*MY)
