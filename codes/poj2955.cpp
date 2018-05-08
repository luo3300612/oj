#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
int dp[101][101];
int main()
{
    char s[102];
    cin.getline(s,101);
    while(strcmp(s,"end"))
    {
        int len=1;
        while(s[len]!='\0'){
            len++;
        }
        for(int i=len;i>=1;i--){
            s[i]=s[i-1];
        }
        memset(dp,0,sizeof(dp));
        for(int j=2;j<=len;j++){
            for(int i=j-1;i>=1;i--){
                dp[i][j]=dp[i][j-1];
                if(s[j]=='['||s[j]=='('){
                    continue;
                }
                else{
                    for(int k=i;k<j;k++){
                        if((s[k]=='['&&s[j]==']')||(s[j]==')'&&s[k]=='(')){
                            dp[i][j]=max(2+dp[i][k-1]+dp[k+1][j-1],dp[i][j]);
                        }
                    }
                }
            }
        }
        cout<<dp[1][len]<<endl;
        cin.getline(s,101);
    }
}