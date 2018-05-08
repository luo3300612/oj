#include<cstdio>
#include<memory.h>
#include<cmath>
using namespace std;
int main(){
    char c;
    double T,D,H,tmp;
    int mark[4];
    bool flag=false;
    int i;
    while(1){
        i=2;
        memset(mark,0,sizeof(mark));
        while(i--){
            scanf(" %c",&c);
            switch(c){
                case 'T':scanf("%lf",&T),mark[1]=1;
                break;
                case 'D':scanf("%lf",&D),mark[2]=1;
                break;
                case 'H':scanf("%lf",&H),mark[3]=1;
                break;
                case 'E':flag=1;
                break;
            }
            if(flag){
                break;
            }
        }
        if(flag){
            break;
        }
        if(mark[1]==1&&mark[2]==1){
            printf("T %.1lf D %.1f H %.1f\n",T,D,T+(0.5555)*(6.11*exp(5417.7530*((1.0/273.16)-(1.0/(D+273.16))))-10.0));
        }
        else if(mark[1]==1&&mark[3]==1){
            printf("T %.1lf D %.1f H %.1f\n",T,1.0/(1.0/273.16-log(((H-T)/0.5555+10)/6.11)/5417.7530)-273.16,H);
        }
        else{
            printf("T %.1lf D %.1f H %.1f\n",H-(0.5555)*(6.11*exp(5417.7530*((1.0/273.16)-(1.0/(D+273.16))))-10.0),D,H);
        }
    }
}