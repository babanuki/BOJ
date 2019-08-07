#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int moveX[2]={1, 0};
int moveY[2]={0, 1};
int ans=1, n;
char board[54][54];

void swap(int x, int y, int k){
	char tmp;
	tmp=board[x][y];
	board[x][y]=board[x+moveX[k]][y+moveY[k]];
	board[x+moveX[k]][y+moveY[k]]=tmp;
}

void chkMax(int x, int y){
	int cnt=1;
	for(int i=0; i<n; i++)
		if(board[x][i]==board[x][i+1])
			ans=max(ans, ++cnt);
		else
			cnt=1;
	cnt=1;
	for(int i=0; i<n; i++)
		if(board[i][y]==board[i+1][y])
			ans=max(ans, ++cnt);
		else
			cnt=1;
}

int main(){
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%s",board[i]);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<2; k++){
				if(i+moveX[k]>=n || j+moveY[k]>=n)
					continue;
				char tmp;
				swap(i, j, k);
				chkMax(i, j);
				chkMax(i+moveX[k], j+moveY[k]);
				swap(i, j, k);
			}
		}
	}
	printf("%d",ans);
	
	return 0;
}