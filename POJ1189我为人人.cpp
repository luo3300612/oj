#include<stdio.h>
#include<memory.h>
long long mark[52][52];
long long num[52][52];
int N;
int m;
long long gcd(long long m,long long n){
	return n==0?m:gcd(n,m%n);
}
int main(){
	scanf("%d %d",&N,&m);
	char c;
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			scanf(" %c",&c);
			if(c=='*'){
				mark[i][j]=1;
			}
		}
	}
	memset(num,0,sizeof(num));
	num[1][1]=1LL<<N; 	
	for(int i=1;i<=N+1;i++){
		for(int j=1;j<=i;j++){
			if(mark[i][j]==1){
				num[i+1][j]+=num[i][j]>>1;
				num[i+1][j+1]+=num[i][j]>>1;
			}
			else{
				num[i+2][j+1]+=num[i][j];
			}
		}
	}
	long long deno=0;
	for(int i=1;i<=N+1;i++){
		deno+=num[N+1][i];
	}
	long long gc=gcd(deno,num[N+1][m+1]);
	printf("%lld/%lld\n",num[N+1][m+1]/gc,deno/gc);
	return  0;
}
