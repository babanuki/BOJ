#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define N 100000

long long ans[N+1], chk[N+1];
vector<long long> p;

void prime(){
	for(int i=2; i<N+1; i++)
		chk[i]=i;
	
	for(int i=2; i<sqrt(N)+1; i++){
		if(chk[i]==i)
			for(int j=i*i; j<N+1; j+=i){
				if(chk[j]==j);
					chk[j]=i;
			}
	}
	
	for(int i=2; i<N+1; i++)
		if(chk[i]==i)
			p.push_back(i);
	
	return;
}

long long func(long long n){
	long long tmp=214748364700;
	
    for(int j=0; j<p.size(); j++){
        for(int k=j+1; k<p.size(); k++){
			if(p[j]*p[k]>=n)
				tmp=min(tmp, p[j]*p[k]);
        }
    }
	
	return ans[n]=tmp;
}

int main(){
	int t;
    long long k;
	
	scanf("%d",&t);
	
	prime();
	
	while(t--){
		scanf("%lld",&k);
		
		if(ans[k]){
			printf("%lld\n", ans[k]);
			
			continue;
		}
		else if(k<7){
			printf("6\n");
			
			continue;
		}
		
		printf("%lld\n", func(k));
	}
	
	return 0;
}