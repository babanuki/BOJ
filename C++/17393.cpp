#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> A;
vector<long long> B;

int main(){
	int n;
	long long a, b;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%lld",&a);
		A.push_back(a);
	}
	
	for(int i=0; i<n; i++){
		scanf("%lld",&b);
		B.push_back(b);
	}
	
	for(int i=0; i<n; i++)
		printf("%d ", upper_bound(B.begin(), B.end(), A[i])-B.begin()-i-1);
	
	return 0;
}