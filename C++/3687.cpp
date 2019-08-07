#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

int need[10]={6,2,5,5,4,5,6,3,7,6};
int cache[16][104];
string Min;

int canDo(int x, int v){
	int &ret=cache[x][v];
	
	if(ret!=-1)
		return ret;
	if(x<1)
		return ret=!v;
	if(v<1)
		return ret=0;
		
	ret=0;
	
	for(int i=0; i<10; i++)
		if(v-need[i]>-1)
			ret|=canDo(x-1, v-need[i]);
			
	return ret;
}

void makeMin(int x, int v, bool ttl){
	if(v<1)
		return;
	
	int i=(ttl)?1:0;
	
	for(; i<10; i++){
		if(v-need[i]>-1 && canDo(x-1, v-need[i])){
			Min+=char(i+48);
			makeMin(x-1, v-need[i], false);
			return;
		}
	}
}

void makeMax(int n){
	string Max=("");
	
	if(n%2){
		Max+='7';
		n-=3;
	}
	
	while(n!=0){
		Max+='1';
		n-=2;
	}
	
	cout << Max << endl;
}

int main(){
	memset(cache, -1, sizeof(cache));
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Min=("");
		makeMin(((n%7)?1:0)+n/7, n, true);
		cout << Min << ' ';
		makeMax(n);
	}
	
	return 0;
}