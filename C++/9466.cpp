#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 100004

bool visited[N], cycleChk[N];
vector<int> v;
int CNT;

int cycleSize(int x, int y){
    int cnt=1;
    for(int i=y; i!=x; i=v[i])
        cnt++;
    return cnt;
}

void dfs(int x){
    visited[x]=true;
    if(!visited[v[x]])
        dfs(v[x]);
    else if(!cycleChk[v[x]])
            CNT+=cycleSize(x, v[x]);
    cycleChk[x]=true;
}

int main(){
    int t, n;
    scanf("%d",&t);
    while(t--){
        CNT=0;
        v.clear();
        scanf("%d",&n);
        v.resize(n+4);
        memset(visited, false, sizeof(visited));
        memset(cycleChk, false, sizeof(cycleChk));
        for(int i=0; i<n; i++){
            int x;
            scanf("%d",&x);
            v[i]=x-1;
        }
        for(int i=0; i<n; i++)
            if(!visited[i])
                dfs(i);
        printf("%d\n", n-CNT);
    }
    
    return 0;
}