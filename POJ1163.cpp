#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 101
int N;
int maxV[MAX][MAX];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&maxV[i][j]);
		} 
	}
	for(int i=N-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			maxV[i][j]=maxV[i][j]+max(maxV[i+1][j],maxV[i+1][j+1]);
		}
	}
	printf("%d",maxV[1][1]);
} 
