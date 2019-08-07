#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;

int main(){
	int n, now=0, k, m, a, cnt=1;
	
	scanf("%d%d",&n,&k);
	
	for(int i=0; i<n; i++){
		scanf("%d",&a);
		
		v.push_back(a);
	}
	
	for(int i=0; i<n; i++){
		now=v[now];
		if(now==k){
			printf("%d", cnt);
			
			return 0;
		}
		cnt++;
	}
	
	printf("-1");
	
	return 0;
}