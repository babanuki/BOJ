#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

int parent[100004];
long long sz[100004];
bool chk[100004];

int Find(int x){
	return x==parent[x]?x:parent[x]=Find(parent[x]);
}

long long Union(int x, int y){
	long long tmp;
	
	tmp=sz[parent[parent[x]]]*sz[parent[y]];
	sz[parent[y]]+=sz[parent[parent[x]]];
	parent[parent[x]]=parent[y];
	
	return tmp;
}

int main(){
	int n, m, q, x, y, choice;
	long long ans=0;
	vector<pair<int, int> > v;
	stack<int> st;
	
	scanf("%d%d%d",&n,&m,&q);
	
	for(int i=1; i<n+1; i++){
		parent[i]=i;
		sz[i]=1;
	}
	
	for(int i=0; i<m; i++){
		scanf("%d%d",&x,&y);
		
		v.push_back(make_pair(x, y));
	}
	
	for(int i=0; i<q; i++){
		scanf("%d",&choice);
		
		chk[choice-1]=true;
		st.push(choice-1);
	}
	
	for(int i=0; i<m; i++){
		if(chk[i])
			continue;
		
		if(Find(v[i].first)==Find(v[i].second))
			continue;
		
		Union(v[i].first, v[i].second);
	}
	
	while(!st.empty()){
		int next=st.top();
		
		st.pop();
		
		if(Find(v[next].first)==Find(v[next].second))
			continue;
		
		ans+=Union(v[next].first, v[next].second);
	}
	
	printf("%lld", ans);
	
	return 0;
}