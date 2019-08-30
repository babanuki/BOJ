#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n, k;
	long long a[300004], sum[300004], ans=0;
	
	scanf("%d%d",&n,&k);
	
	for(int i=0; i<n; i++)
		scanf("%lld",&a[i]);
	
	sort(a, a+n);
	
	sum[0]=a[0];
	
	for(int i=0; i<n-1; i++)
		sum[i+1]=sum[i]+a[i+1];
	
	for(int i=0; i<k; i++)
		ans+=sum[n-1]-sum[i];
	
	printf("%lld", ans);
	
	return 0;
}