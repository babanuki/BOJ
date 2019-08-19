#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000004

vector<int> nxt[N];
int n, q, l, r=-1, maxdepth, maxlayer;
int sum[N], dp[N], layer[N], depth[N], k[N];

double func(int y, int x){
	return (double)(sum[y+1]-sum[x+1])/(x-y);
}

void before(int x){
	while(l<r && func(layer[r-1], layer[r])>=func(layer[r], x))
		r--;
		
	layer[++r]=x;
	
	return;
}

void dfs(int x){
	maxdepth=max(maxdepth, depth[x]);
	
	sum[depth[x]]++;
	
	for(int i=0; i<nxt[x].size(); i++){
		depth[nxt[x][i]]=depth[x]+1;
		
		dfs(nxt[x][i]);
	}
	
	return;
}

int main(){
	int x;
	
	scanf("%d%d",&n,&q);
	
	for(int i=1; i<=q; i++){
		scanf("%d",&k[i]);
		maxlayer=max(maxlayer, k[i]);
	}
	
	for(int i=2; i<=n; i++){
		scanf("%d",&x);
		nxt[x].push_back(i);
	}
	
	depth[1]=1;
	
	dfs(1);
	
	for(int i=maxdepth-1; i>0; i--)
		sum[i]+=sum[i+1];
	
	for(int i=0; i<maxdepth; i++)
		before(i);
	
	for(int i=1; i<=maxlayer; i++){
		while(l<r && func(layer[l], layer[l+1])<i)
			l++;
	
		dp[i]=layer[l]+(sum[layer[l]+1]+i-1)/i;
	}
	
	for(int i=1; i<q; ++i)
		printf("%d ", dp[k[i]]);
    	printf("%d", dp[k[q]]);
	
	return 0;
}