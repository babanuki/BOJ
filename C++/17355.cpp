#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 1000000007

vector<vector<int> > v;
vector<int> prime;
int chk[10000004];
int cntUP[10000004], cntDOWN[10000004];

void primeChk(int num){
	for(int i=2; i<num+1; i++)
		chk[i]=i;
	
	for(int i=2; i<sqrt(num)+1; i++)
		if(chk[i]==i)
			for(int j=i*i; j<num+1; j+=i)
				if(chk[j]==j)
					chk[j]=i;
	
	for(int i=2; i<num+1; i++)
		if(chk[i]==i){
			prime.push_back(i);
			v[i].push_back(i);
		}
}

void withPrime(int num){
	int tmp=num;
	
	for(int i=0; i<prime.size(); i++){
		if(v[tmp].size()!=0){
			v[num].insert(v[num].end(), v[tmp].begin(), v[tmp].end());
			break;
		}
		
		while(tmp%prime[i]==0){
			v[num].push_back(prime[i]);
			tmp/=prime[i];
			if(tmp==1)
				break;
		}
		
		if(tmp==1)
			break;
	}
}

void result(){
	long long UP=1, DOWN=1;
	
	for(int i=2; i<10000001; i++){
		if(cntUP[i]>0 && cntDOWN[i]>0){
			if(cntUP[i]>=cntDOWN[i]){
				cntUP[i]-=cntDOWN[i];
				cntDOWN[i]=0;
			}
			else{
				cntDOWN[i]-=cntUP[i];
				cntUP[i]=0;
			}
		}
		
		while(cntUP[i]--){
			UP*=i;
			UP%=N;
		}
		while(cntDOWN[i]--){
			DOWN*=i;
			DOWN%=N;
		}
	}
	
	printf("%lld %lld", UP, DOWN);
}

int main(){
	int n, a, b;
	v.resize(10000004);
	
	scanf("%d",&n);
	
	primeChk(10000000);
	
	for(int i=0; i<n; i++){
		scanf("%d%d",&a,&b);
		
		if(v[b-a].size()==0)
			withPrime(b-a);
		if(v[b].size()==0)
			withPrime(b);
			
		for(int j=0; j<v[b-a].size(); j++)
			cntUP[v[b-a][j]]++;
		for(int j=0; j<v[b].size(); j++)
			cntDOWN[v[b][j]]++;
	}
	
	result();
	
	return 0;
}