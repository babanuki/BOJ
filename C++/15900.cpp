#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool visited[500004];
vector<vector<int> > g;
long long ans;

void dfs(int x, int cnt){
	int tmp=0;
	
	visited[x]=true;
	
	for(int i=0; i<g[x].size(); i++)
		if(!visited[g[x][i]]){
			dfs(g[x][i], cnt+1);
			tmp++;
		}
	
	if(tmp==0)
		ans+=cnt;
		
	return;
}

int main(){
	int n, x, y;
	
	scanf("%d",&n);
	
	g.resize(n+4);
	
	for(int i=0; i<n-1; i++){
		scanf("%d%d",&x,&y);
		
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(1, 0);
	
	printf("%s", ans%2?"Yes":"No");
}