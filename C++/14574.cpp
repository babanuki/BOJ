#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> parent;
vector<vector<int> > g;
vector<long long> p, c;
vector<pair<pair<long long, int>, int> > v;
bool visited[1004];

int Find(int a){
	return a==parent[a]?a:parent[a]=Find(parent[a]);
}

void Union(int a, int b){
	parent[parent[a]]=parent[b];
	
	return;
}

void dfs(int s){
	visited[s]=true;
	
	for(int i=0; i<g[s].size(); i++){
		if(visited[g[s][i]])
			continue;
		
		dfs(g[s][i]);
		
		printf("%d %d\n", s+1, g[s][i]+1);
	}
	
	return;
}

int main(){
	int n;
	long long px, cx, ans=0;
	
	scanf("%d",&n);
	
	g.resize(n+4);
	
	for(int i=0; i<n; i++){
		scanf("%lld%lld",&px,&cx);
		
		p.push_back(px);
		c.push_back(cx);
		parent.push_back(i);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)
				continue;
			
			v.push_back(make_pair(make_pair(-(c[i]+c[j])/abs(p[i]-p[j]), i), j));
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<v.size(); i++){
		int a=v[i].first.second, b=v[i].second;
		long long cost=v[i].first.first;
		
		if(Find(a)==Find(b))
			continue;
		
		Union(a, b);
		
		g[a].push_back(b);
		g[b].push_back(a);
		
		ans+=cost;
	}
	
	printf("%lld\n", -ans);
	
	dfs(0);
	
	return 0;
}