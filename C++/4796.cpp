#include<cstdio>

int main(){
	for(int i=1; ; i++){
		int l, p, v;
		scanf("%d%d%d",&l,&p,&v);
		
		if(l==0)
			return 0;
		
		printf("Case %d: %d\n", i, (v/p*l)+((v%p)>l?l:v%p));
	}
	
	return 0;
}