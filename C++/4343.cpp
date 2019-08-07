#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int parent[504];

int Find(int x){
	return x==parent[x]?x:parent[x]=Find(parent[x]);
}

void Union(int x, int y){
	parent[parent[x]]=parent[y];
}

int main(){
	int n;
	
	scanf("%d",&n);
	
	while(n--){
		int s, p, x, y, cnt=0;
		
		scanf("%d%d",&s,&p);
		
		vector<pair<int, int> > v;
		vector<pair<int, pair<int, int> > > dist;
		
		for(int i=0; i<p; i++){
			parent[i]=i;
			
			scanf("%d%d",&x,&y);
			
			v.push_back(make_pair(x, y));
			
			for(int j=0; j<i; j++)
				dist.push_back(make_pair((x-v[j].first)*(x-v[j].first)+(y-v[j].second)*(y-v[j].second), make_pair(i, j)));
		}
		
		sort(dist.begin(), dist.end());
		
		for(int i=0; i<dist.size(); i++){
			if(Find(dist[i].second.first)==Find(dist[i].second.second))
				continue;
				
			cnt++;
			Union(dist[i].second.first, dist[i].second.second);
			
			if(cnt+s==p){
				printf("%.2f\n", sqrt(dist[i].first));
				
				break;
			}
		}
	}
	
	return 0;
}