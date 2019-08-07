#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 1e18

vector<long long> X, Y;
long long x, y;
int n;

long long func(int x, vector<long long> &v){
	long long result=0;
	
	for(int i=0; i<n; i++)
		result+=abs(v[i]-x);
		
	return result;
}

long long ternarySearch(vector<long long> &v){
	int low=-1000004, high=1000004, ctrL, ctrR;
	long long result=MAX;
	
	while(high-low>2){
		ctrL=(2*low+high)/3;
		ctrR=(low+2*high)/3;
		if(func(ctrL, v)<=func(ctrR, v))
			high=ctrR;
		else
			low=ctrL;
	}
	
	for(int i=low; i<=high; i++)
		result=min(result, func(i, v));
	
	return result;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%lld%lld",&x,&y);
		
		X.push_back(x);
		Y.push_back(y);
	}
	
	printf("%lld", ternarySearch(X)+ternarySearch(Y));
	
	return 0;
}