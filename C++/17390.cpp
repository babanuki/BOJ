#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
long long t[1200004];

int upd(int n, int s, int e, int p, long long v){
	if(p<s||p>e)
		return 0;
		
	if(s==e)
		t[n]=v;
	else{
		upd(2*n, s, (s+e)/2, p, v);
		upd(2*n+1, (s+e)/2+1, e, p, v);
		t[n]=t[2*n]+t[2*n+1];
	}
}

long long sum(int n, int s, int e, int l, int r){
	if(l>e||r<s)
		return 0;
	if(l<=s && e<=r)
		return t[n];
		
	return sum(2*n, s, (s+e)/2, l, r)+sum(2*n+1, (s+e)/2+1, e, l, r);
}

int main(){
	int n, q, x;
	
	scanf("%d%d",&n,&q);
	
	for(int i=1; i<n+1; i++){
		scanf("%d",&x);
		
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++)
		upd(1,1,n,i+1,v[i]);
	
	for(int i=0; i<q; i++){
		int a, b;
		
		scanf("%d%d",&a,&b);
		
		printf("%lld\n",sum(1,1,n,a,b));
	}
	
	return 0;
}