#include<cstdio>

int a[14], ans[14];
bool chk[14];

int main(){
	int n, cnt;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	for(int i=0; i<n; i++){
		cnt=0;
		
		for(int j=0; j<n; j++){
			if(chk[j])
				continue;
			
			if(cnt==a[i]){
				chk[j]=true;
				ans[j]=i;
				
				break;
			}
			
			cnt++;
		}
	}
	
	for(int i=0; i<n; i++)
		printf("%d ", ans[i]+1);
	
	return 0;
}