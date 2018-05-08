#include<stdio.h>
#include<memory.h>
using namespace std;
int mark[51][102];
int deno[52][102];
int num[52][102];
int N;
int m;
int resDeno;
int resNum;
int gcd(int m,int n){
	return n==0?m:gcd(n,m%n);
}
void fractionAdd(int deno1,int num1,int deno2,int num2){
	resDeno=deno1*deno2/gcd(deno1,deno2);
	resNum=resDeno/deno1*num1+resDeno/deno2*num2;
	int gc=gcd(resDeno,resNum);
	resDeno/=gc;
	resNum/=gc;
}
int main(){
	scanf("%d %d",&N,&m);
	char c;
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			scanf(" %c",&c);
			if(c=='*'){
				mark[i][j*2]=1;
			}
		}
	}
	memset(num,0,sizeof(num));
	for(int i=0;i<=51;i++){
		for(int j=0;j<=101;j++){
			deno[i][j]=1;
		}
	}
	num[1][2]=1;	
	for(int i=2;i<=N+1;i++){
		for(int j=1;j<=2*i+1;j++){
			if(j%2==0){
				fractionAdd(2*deno[i-1][j-2],num[i-1][j-2]*mark[i-1][j-2],2*deno[i-1][j],num[i-1][j]*mark[i-1][j]);
				fractionAdd(resDeno,resNum,deno[i-1][j-1],num[i-1][j-1]);
				num[i][j]=resNum;
				deno[i][j]=resDeno;	
			}
			else{
				num[i][j]=num[i-1][j-1]*(!mark[i-1][j-1]);
				deno[i][j]=deno[i-1][j-1];
			}
		}
	}
	if(num[N+1][m*2+2]==0){
		printf("0/1\n");
	}
	else{
		printf("%d/%d\n",num[N+1][m*2+2],deno[N+1][m*2+2]);
	}
	
	/*
	for(int i=1;i<=N+1;i++){
		for(int j=1;j<=2*i+1;j++){
			printf("%d ",num[i][j]);
		}
		printf("\n");
		for(int j=1;j<=2*i+1;j++){
			printf("- "); 
		}
		printf("\n");
		for(int j=1;j<=2*i+1;j++){
			printf("%d ",deno[i][j]);
		}
		printf("\n\n");
	}
	*/
	
}
