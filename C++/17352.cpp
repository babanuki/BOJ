#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > v;
bool visited[300004];

void dfs(int x){
    visited[x]=true;
    
    for(int i=0; i<v[x].size(); i++)
        if(!visited[v[x][i]])
            dfs(v[x][i]);
            
    return;
}

int main(){
	int n, x, y, A, B;
	
	scanf("%d",&n);
	
	if(n==2){
		printf("1 2");
		
		return 0;
	}
	
	v.resize(n+4);
	
	for(int i=0; i<n-1; i++){
		scanf("%d%d",&x,&y);
		
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	dfs(1);
	
	for(int i=1; i<n+1; i++){
		if(visited[i]==true)
			A=i;
		else
			B=i;
	}
	
	printf("%d %d", A, B);
	
	return 0;
}