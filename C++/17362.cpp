#include<cstdio>

int main(){
	int n;
	
	scanf("%d",&n);
	
	switch(n%8){
		case 1:
			printf("1");
			return 0;
		case 2:
		case 0:
			printf("2");
			return 0;
		case 3:
		case 7:
			printf("3");
			return 0;
		case 4:
		case 6:
			printf("4");
			return 0;
		case 5:
			printf("5");
            return 0;
	}
}