#include<cstdio>

int main(){
	int n, k, a, b;
	unsigned long long result=0;
	
	scanf("%d%d",&n,&k);
	
	for(int i=0; i<n; i++){
		
		scanf("%d%d",&a,&b);
		
		for(int j=0; j<b; j++)
			result=(10*result+a)%k;
	}
	
	printf("%llu", result);
	
	return 0;
}