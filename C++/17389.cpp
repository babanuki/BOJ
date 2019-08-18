#include<cstdio>
#include<cstring>

int main(){
	char str[10004];
	int n, bonus=0, ans=0;
	
	scanf("%d",&n);
	scanf("%s",str);
	
	for(int i=0; i<n; i++){
		if(str[i]=='X')
			bonus=0;
		else{
			ans+=i+1+bonus;
			bonus++;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}