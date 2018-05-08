#include<stdio.h>
using namespace std;
int main(){
	int a,b;
	while(1){
		scanf("%d%d",&a,&b);
		a^=b;
		b^=a;
		a^=b;
		printf("%d %d",a,b);
	}
	
} 
