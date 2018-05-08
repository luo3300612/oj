#include<stdio.h>
#include<memory.h>
long long mark[52][105];
long long deno[52][105];
long long num[52][105];
int N;
int m;
long long resDeno;
long long resNum;
long long gcd(long long m,long long n){
	return n==0?m:gcd(n,m%n);
}
void fractionAdd(long long deno1,long long num1,long long deno2,long long num2){
	resDeno=deno1*deno2;
	resNum=num2*deno1+num1*deno2;
	long long gc=gcd(resDeno,resNum);
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
		for(int j=0;j<=104;j++){
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
				if(mark[i-1][j-1]==0){
					num[i][j]=num[i-1][j-1];
					deno[i][j]=deno[i-1][j-1];
				}
				else{
					num[i][j]=0;
					deno[i][j]=1;
				}
			}
		}
	}
	printf("%lld/%lld\n",num[N+1][m*2+2],deno[N+1][m*2+2]);
	return  0;
}
