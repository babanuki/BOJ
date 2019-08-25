import sys
read=sys.stdin.readline

N, M=map(int, read().split())

str1, str2=map(str, read().split())

d=[['AFHKM',3], ['BDNPQRTXY',2], ['CGIJLOSUVWZ',1], ['E',4]]
l=[]

game=""

if len(str1)>len(str2):
    for i in range(len(str2)):
        game+=str1[i]
        game+=str2[i]

    game+=str1[len(str2):]
else:
    for i in range(len(str1)):
        game+=str1[i]
        game+=str2[i]

    game+=str2[len(str1):]

for i in range(N+M):
    for j in range(4):
        if game[i] in d[j][0]:
            l.append(d[j][1])
            
            break

for i in range(N+M-2):
    tmp=[]
    
    for j in range(len(l)-1):
        tmp.append((l[j]+l[j+1])%10)

    l=tmp

if l[0] is not 0:
    print(str(l[0])+str(l[1])+'%')
else:
    print(str(l[1])+'%')
