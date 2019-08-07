#include<cstdio>
#include<vector>
using namespace std;

vector<long long> v;

int main(){
	int n, m, a;
	long long now=0, ans=0;
	
	scanf("%d%d",&n,&m);
	v.resize(m+4);
	
	for(int i=0; i<n; i++){
		scanf("%d",&a);
		now=(now+a)%m;
		v[now]++;
	}
	
	v[0]++;
	
	for(int i=0; i<v.size(); i++)
		ans+=v[i]*(v[i]-1);
	
	printf("%lld", ans/2);
	
	return 0;
}