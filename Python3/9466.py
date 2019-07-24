import sys
sys.setrecursionlimit(10**8)

read=sys.stdin.readline

def dfs(x, path):
    global CNT, visited, g
    path.append(x)
    visited[x]=1
    if visited[g[x]]:
        if x==g[x]:
            CNT+=1
        else:
            try:
                CNT+=len(path)-path.index(g[x])
            except:
                return
    else:
        dfs(g[x], path)

t=int(read())

while t:
    t-=1
    CNT=0
    n=int(read())
    visited=[0]*(n+1)
    g=[0]+list(map(int, read().split()))
    for i in range(1, n+1):
        if not visited[g[i]]:
            dfs(g[i], [])
    print(n-CNT)





'''

for _ in range(int(input())):
	n = int(input())
	ind, ck = [0] * (n+1), [0] * (n+1)
	h,r = 0,0
	nxt = [0] + list(map(int,input().split()))
	for i in nxt:
		ind[i] += 1
	for i in range(1,n+1):
		h = i
		while ind[h] == 0 and ck[h] == 0:
			ck[h] = 1
			ind[nxt[h]] -= 1
			h = nxt[h]
			r += 1
	print(r)


주석 처리된 부분은 psychobabo님이 작성한 코드입니다,
제가 작성한 건, 전체에서 사이클의 크기를 구한 코드지만,
psychobabo님은 전체에서 사이클에 포함되지 않는 노드의 수를 구했습니다.

'''
