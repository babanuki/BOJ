#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<long long, long long> > fish;
vector<pair<long long, int> > human;
int sum[200004], ans[200004];

int main(){
	int n, m;
	long long le, x, y;
	
	scanf("%d%d%lld",&n,&m,&le);
	
	for(int i=0; i<n; i++){
		scanf("%lld%lld",&x,&y);
		
		fish.push_back(make_pair(x, y));
	}
	
	for(int i=0; i<m; i++){
		scanf("%lld",&x);
		
		human.push_back(make_pair(x, i));
	}
	
	sort(human.begin(), human.end());
	
	for(int i=0; i<n; i++){
		if(le<fish[i].second)
			continue;
		
		long long l=fish[i].first+fish[i].second-le;
		long long r=fish[i].first-fish[i].second+le;
		
		sum[lower_bound(human.begin(), human.end(), make_pair(l, 0))-human.begin()]++;
		sum[upper_bound(human.begin(), human.end(), make_pair(r, 2147483647))-human.begin()]--;
	}
	
	for(int i=0; i<m; i++){
		ans[human[i].second]=sum[i];
		sum[i+1]+=sum[i];
	}
	
	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}