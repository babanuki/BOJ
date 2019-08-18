#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 1050000000

int n, g[104][104];

void floyd_warshall(){
	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++)
			for(int k=1; k<n+1; k++)
				g[j][k]=min(g[j][k], g[i][k]+g[j][i]);
}

int main(){
	int k, choice, x, y, cost;
	bool changed;
	
	scanf("%d%d",&n,&k);
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++)
			g[i][j]=MAX;
		g[i][i]=0;
	}
	
	for(int i=0; i<k; i++){
		scanf("%d",&choice);
		
		if(!choice){
			scanf("%d%d",&x,&y);
			
			if(g[x][y]==MAX)
				printf("-1\n");
			else
				printf("%d\n", g[x][y]);
				
			continue;
		}
		
		scanf("%d%d%d",&x,&y,&cost);
		
		if(g[x][y]<=cost)
			continue;
		g[x][y]=g[y][x]=cost;
		floyd_warshall();
	}
}