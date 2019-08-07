#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<pair<int, int> > item;
int cache[104][100004], n;

int dp(int x, int cap){
	if(x>n-1)
		return 0;
	int &ret=cache[x][cap];
	if(ret!=-1)
		return ret;
	ret=dp(x+1, cap);
	if(cap-item[x].first>-1)
		ret=max(ret, dp(x+1, cap-item[x].first)+item[x].second);
	return ret;
}

int main(){
	int k, w, v;
	scanf("%d%d",&n,&k);
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++){
		scanf("%d%d",&w,&v);
		item.push_back(make_pair(w, v));
	}
	printf("%d", dp(0, k));
}