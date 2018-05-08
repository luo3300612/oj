#include<stdio.h>
#include<memory>
#include<algorithm>
using namespace std;
const int capacity = 12880;
const int n = 3402;
int dp[capacity+1];
int w[n+1];
int v[n+1];
int N;
int c;
void start(){
    for(int i = 1; i <= N; i++){
        for(int j = c; j >= w[i]; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
}
int main(){
    scanf("%d%d",&N,&c);
    for(int i = 1;i <= N; i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    start();
    printf("%d",dp[c]);
    return 0;
}