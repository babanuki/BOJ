#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;

int main(){
	int n, i, x, price, pickup;
	
	scanf("%d%d",&n,&x);
	
	for(int i=0; i<n; i++){
		scanf("%d",&price);
		v.push_back(price);
	}
	
	if(n==1){
		printf("1");
		
		return 0;
	}
	
	sort(v.begin(), v.end());
	
	for(i=1; i<v.size(); i++){
		pickup=v[i]+v[i-1];
		if(pickup>x)
			break;
	}
	
	printf("%d", i);
	
	return 0;
}