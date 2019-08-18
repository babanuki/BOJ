#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

vector<vector<int> > g;
int ans;
bool visited[54];

void dfs(int s){
	bool chk=false;
	
	if(visited[s])
		return;
	
	visited[s]=true;
	
	for(int i=0; i<g[s].size(); i++){
		if(!visited[g[s][i]]){
			dfs(g[s][i]);
			chk=true;
		}
	}
	
	if(!chk)
		ans++;
	
	return;
}

int main(){
	int n, whos, s, target;
	
	scanf("%d",&n);
	
	g.resize(n+1);
	
	for(int i=0; i<n; i++){
		scanf("%d",&whos);
		
		if(whos==-1)
			s=i;
		else
			g[whos].push_back(i);
	}
	
	scanf("%d",&target);
	
	visited[target]=true;
	
	dfs(s);
	
	printf("%d",ans);
	
	return 0;
}