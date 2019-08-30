#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int> > v;

int main(){
	int n, m, a, b;
	long long ans=0;
	
	scanf("%d%d",&n,&m);
	
	for(int i=0; i<n; i++){
		scanf("%d%d",&a,&b);
		
		v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n-1; i++)
		if(v[i+1].second<v[i].second)
			ans+=v[i].second-v[i+1].second;
	
	ans+=v[n-1].second;
	
	printf("%lld", ans);
	
	return 0;
}