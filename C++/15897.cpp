#include<cstdio>

int main(){
	int n, x, y;
	long long ans=0, tmp=0;
	
	scanf("%d",&n);
	
	for(int i=1; i<n+1; i+=tmp){
		x=(n-1)/i, y=(n-1)%i;
		tmp=(x==0?1:y/x+1);
		ans+=(x+1)*tmp;
	}
	
	printf("%lld", ans);
	
	return 0;
}