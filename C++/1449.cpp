#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n, l, x, ctr, ans=1;
	vector<int> v;
	scanf("%d%d",&n,&l);
	while(n--){
		scanf("%d",&x);
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	ctr=v[0];
	for(int i=0; i<v.size(); i++){
		if(v[i]>=ctr+l)
			ctr=v[i], ans++;
	}
	
	printf("%d", ans);
	
	return 0;
}