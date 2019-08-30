#include<cstdio>

int main(){
	int a, b;
	long long ans=1;
	
	scanf("%d%d",&a,&b);
	
	for(int i=a; i<b+1; i++){
		ans*=i*(i+1)/2;
		ans%=14579;
	}

	printf("%lld", ans);
	
	return 0;
}