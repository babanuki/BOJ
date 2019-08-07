#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

priority_queue<long long> pq;

int main(){
	int n, m, x, y;
	long long sum, ans=0, a, b;
	
	scanf("%d%d",&n,&m);
	
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		
		pq.push(-x);
	}
	
	for(int i=0; i<m; i++){
		a=pq.top();
		pq.pop();
		b=pq.top();
		pq.pop();
		
		sum=a+b;
		pq.push(sum);
		pq.push(sum);
	}
	
	while(pq.size()){
		ans+=pq.top();
		pq.pop();
	}
	
	printf("%lld", -ans);
	
	return 0;
}