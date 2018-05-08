#include<stdio.h>
#include <memory.h>
#include<algorithm>
using namespace std;
int maxV[101][101];
int d[101][101];
int F;
int V;
int main(){
	scanf("%d%d",&F,&V);
	for(int i=1;i<=F;i++){
		for(int j=1;j<=V;j++){
			scanf("%d",&d[i][j]);
		}
	}
	memset(maxV,0,sizeof(maxV));
	for(int i=1;i<=F;i++){
		for(int j=i;j<=V;j++){
			if(i==j){maxV[i][j]=maxV[i-1][j-1]+d[i][j];continue;} 
			maxV[i][j]=max(maxV[i][j-1],maxV[i-1][j-1]+d[i][j]);
		}
	}
	printf("%d",maxV[F][V]);
}
