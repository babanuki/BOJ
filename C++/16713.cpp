#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;
vector<int> result;
vector<int> ans;

int main(){
	int n, m, x, y, ctr;
	
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		v.push_back(x);
	}
	
	result.push_back(0);
	
	for(int i=1; i<n; i++)
		result.push_back(v[i]^result[i-1]);
		
	for(int i=0; i<m; i++){
		scanf("%d%d",&x,&y);
		ans.push_back(result[y-1]^result[x-1]^v[x-1]);
	}
	
	ctr=ans[0];
	
	for(int i=1; i<ans.size(); i++){
		ctr^=ans[i];
	}
	
	printf("%d", ctr);
	
	return 0;
}