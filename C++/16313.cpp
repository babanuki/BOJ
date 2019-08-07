#include<cstdio>
#include<cmath>

int main(){
	int a, b, c, d;
	double s;
	
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	s=(double)(a+b+c+d)/2;
	
	printf("%.7f", sqrt((s-a)*(s-b)*(s-c)*(s-d)));
}