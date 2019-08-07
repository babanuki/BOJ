#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int> > v;
vector<int> maxDist;
int n, x, y, ans, MIN=2147483647;

int dist(int x1, int x2, int y1, int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
	scanf("%d",&n);
	maxDist.resize(n+4);
	
	for(int i=0; i<n; i++){
		scanf("%d%d",&x,&y);
		
		v.push_back(make_pair(x, y));
	}
	
	for(int i=0; i<v.size(); i++){
		int MAX=0;
		
		for(int j=0; j<v.size(); j++)
			MAX=max(MAX, dist(v[i].first, v[j].first, v[i].second, v[j].second));
			
		maxDist[i]=MAX;
	}
	
	for(int i=0; i<n; i++)
		if(MIN>maxDist[i]){
			ans=i;
			MIN=maxDist[i];
		}
	
	printf("%d %d", v[ans].first, v[ans].second);
	
	return 0;
}