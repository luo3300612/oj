#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
int w[] = {0, 2, 3, 4, 5};
int v[] = {0, 3, 4, 5, 6};
const int capacity = 8;
const int n = 4;
int dp[n + 1][capacity + 1];
void print(){
    printf("-----------------------\n");
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= capacity; j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}
void start(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= capacity; j++){
            if (j < w[i]){
                dp[i][j] = dp[i - 1][j];
                print();
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                print();
            }
        }
    }
}
int main(){
    memset(dp, 0, sizeof(dp));
    printf("test");
    start();
    return 0;
}