#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int g[6], b, d;
	
	for(int i=0; i<6; i++)
		scanf("%d",&g[i]);
	
	b=max(abs(g[4]-g[0]), abs(g[5]-g[1]));
	d=abs(g[4]-g[2])+abs(g[5]-g[3]);
	
	if(b>d)
		printf("daisy");
	else if(b<d)
		printf("bessie");
	else
		printf("tie");
	
	return 0;
}