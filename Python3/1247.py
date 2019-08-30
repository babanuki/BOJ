import sys
read=sys.stdin.readline

for i in range(3):
    n=int(read())

    ans=0

    for j in range(n):
        ans+=int(read())

    if ans>0:
        print('+')
    elif ans<0:
        print('-')
    else:
        print('0')
