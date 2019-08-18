#include<cstdio>

long long square(int x){
	long long ret=0;
	
	for(int i=1; i<x+1; i++)
		ret+=i*i;
	
	return ret;
}

int main(){
	int n, m, h, tot=0, pt;
	long long ans=0;
	
	scanf("%d%d",&n,&m);
	
	for(int i=0; i<n; i++){
		scanf("%d",&h);
		
		tot+=h+1;
	}
	
	tot=m-tot;
	pt=tot/(n+1);
	
	for(int i=0; i<n+1; i++)
		ans+=square(pt);
	
	for(int i=0; i<tot-pt*(n+1); i++)
		ans+=(pt+1)*(pt+1);
	
	printf("%lld", ans);
	
	return 0;
}