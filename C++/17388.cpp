#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int s, k, h, MIN;
	
	scanf("%d%d%d",&s,&k,&h);
	
	MIN=min(s, min(k, h));
	
	if(s+k+h>99)
		printf("OK");
	else if(MIN==s)
		printf("Soongsil");
	else if(MIN==k)
		printf("Korea");
	else
		printf("Hanyang");
	
	return 0;
}