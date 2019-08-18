#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<int> d;

int main(){
	int n, tmp, q, k;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d",&tmp);
		d.push_back(tmp);
	}
	
	scanf("%d",&q);
	
	while(q--){
		vector<int> dp;
		deque<int> deq;
		
		dp.push_back(0);
		deq.push_back(0);
		
		scanf("%d",&k);
		
		for(int i=1; i<n; i++){
			dp.push_back(2000004);
			
			while(!deq.empty() && deq.front()<i-k)
				deq.pop_front();
			
			dp[i]=dp[deq.front()];
			if(d[i]<d[deq.front()]);
			else
				dp[i]++;
			
			while(!deq.empty()){
				if(d[i]>=d[deq.back()] && dp[i]==dp[deq.back()])
					deq.pop_back();
				else if(dp[i]<dp[deq.back()])
					deq.pop_back();
				else
					break;
			}
			
			deq.push_back(i);
		}
		
		printf("%d\n", dp[n-1]);
	}
	
	return 0;
}