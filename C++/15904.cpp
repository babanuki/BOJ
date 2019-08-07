#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> v;

int main(){
	string s;
	int cnt=0;
	
	getline(cin, s);
	
	for(int i=0; i<s.length(); i++)
		if(s[i]==80 || s[i]==85 || s[i]==67)
			v.push_back(s[i]);
			
	for(int i=0; i<v.size(); i++){
		if(cnt==0 && v[i]=='U')
			cnt++;
		else if(cnt==1 && v[i]=='C')
			cnt++;
		else if(cnt==2 && v[i]=='P')
			cnt++;
		else if(cnt==3 && v[i]=='C')
			cnt++;
	}
	
	if(cnt==4)
		printf("I love UCPC");
	else
		printf("I hate UCPC");
		
	return 0;
}