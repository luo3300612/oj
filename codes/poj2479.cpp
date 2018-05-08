#include<stdio.h>
int T;
int N[50001];
int len;
long long mx(int n){
    int sum1=0,sum2=0;
    int mx1=-99999,mx2=-99999;
    for(int i=1;i<=n;i++){
        if(sum1+N[i]>=0){
            sum1+=N[i];
            if(sum1>mx1){
                mx1=sum1;
            }
        }
        else{
            sum1=0;
        }
    }

    for(int i=n+1;i<=len;i++){
        if(sum2+N[i]>=0){
            sum2+=N[i];
            if(sum2>mx2){
                mx2=sum2;
            }
        }
        else{
            sum2=0;
        }
    }
    return mx1+mx2;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&len);
        for(int i=1;i<=len;i++){
            scanf("%d",&N[i]);
        }
        long long rec=-999999;
        for(int i=1;i<=len;i++){
            if(mx(i)>rec){
                rec=mx(i);
                //printf("%d   %lld  \n",i,rec);
            }
        }
        printf("%lld\n",rec);
    }
}