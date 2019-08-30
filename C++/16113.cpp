#include<cstdio>
#include<vector>
using namespace std;

void inp(int, int);

vector<int> v;
char s[5][20004];
int n;

void func(int x){
	if(x>n/5)
		return;
	
	if(s[0][x]=='#'){
		if(s[4][x]=='.' && s[2][x]=='.'){
			inp(7, x+4);
			return;
		}
		
		if(s[3][x]=='.'){
			if(s[1][x]=='.'){
				inp(3, x+4);
				return;
			}
			
			if(s[1][x+2]=='.'){
				inp(5, x+4);
				return;
			}
			
			if(s[0][x+1]=='.'){
				inp(4, x+4);
				return;
			}
			
			inp(9, x+4);
			return;
		}
		
		if(s[2][x+1]=='#'){
			if(s[3][x+2]=='.'){
				inp(2, x+4);
				return;
			}
			
			if(s[1][x+2]=='#'){
				inp(8, x+4);
				return;
			}
			
			inp(6, x+4);
			return;
		}
		
		if(s[0][x+1]=='#'){
			inp(0, x+4);
			return;
		}
		
		inp(1, x+2);
		return;
	}
	else
		func(x+1);
	
	return;
}

void inp(int num, int nxt){
	v.push_back(num);
	
	func(nxt);
	
	return;
}

int main(){
	char c;
	
	scanf("%d\n",&n);
	
	for(int i=0; i<n; i++){
		scanf("%c",&c);
	
		s[i/(n/5)][i%(n/5)]=c;
	}
	
	func(0);
	
	for(int i=0; i<v.size(); i++)
		printf("%d", v[i]);
	
	return 0;
}