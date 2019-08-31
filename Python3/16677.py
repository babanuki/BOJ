import sys
read=sys.stdin.readline

def func(s1, s2):
    idx=0
    flag=False
    
    for i in range(len(s2)):
        if s2[i]==s1[idx]:
            idx+=1
        if idx==len(s1):
            flag=True
            break

    return flag

m=input()
n=int(read())
g=[]
gbs=0
ans=""

for i in range(n):
    s=read().split()
    if func(m, s[0]):
        s[1]=int(s[1])
        g.append(s)

for i in range(len(g)):
    print(g[i])
    if g[i][1]/(len(g[i][0])-len(m))>gbs:
        gbs=g[i][1]/(len(g[i][0])-len(m))
        ans=g[i][0]

if gbs>0:
    print(ans)
else:
    print("No Jam")
