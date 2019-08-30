#include<cstdio>
#define MOD 1000000007

int main(){
	int n;
	long long ans=1, dp[100004];
	
	scanf("%d",&n);
	
	for(int i=1; i<n+1; i++){
		ans*=i;
		ans%=MOD;
	}
	
	dp[0]=0, dp[1]=1;
	
	for(int i=2; i<n; i++){
		dp[i]=i*(dp[i-1]+dp[i-2]);
		dp[i]%=MOD;
	}

	printf("%lld", ans*dp[n-1]%MOD);
	
	return 0;
}