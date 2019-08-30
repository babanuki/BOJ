#include<cstdio>
 
int main(){
	int x, y;
 
	scanf("%d%d",&x,&y);
 
	printf("%d", (y-x)*(y-x+1)/2);
 
	return 0;
}