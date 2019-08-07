#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

map<char, char> dict;

int main(){
	int n, m;
	char inp[114][114];
	char res[114][114];
	
	scanf("%d%d",&n,&m);
	
	dict['O']='O';
	dict['.']='.';
	dict['-']='|';
	dict['|']='-';
	dict['\\']='/';
	dict['/']='\\';
	dict['^']='<';
	dict['<']='v';
	dict['v']='>';
	dict['>']='^';
	
	for(int i=0; i<n; i++)
		scanf("%s",&inp[i]);
		
    for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			res[m-1-j][i]=dict[inp[i][j]];
        
    for(int i=0; i<m; i++)
        res[i][n]='\0';
			
	for(int i=0; i<m-1; i++)
		printf("%s\n", res[i]);
    printf("%s", res[m-1]);
	
	return 0;
}