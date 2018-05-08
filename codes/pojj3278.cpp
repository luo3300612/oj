#include<stdio.h>
int N,K;
int Step[100001];
int q[100001];
int front=0;
int rear=0;
bool visit[100001];
void BFS(){
    if(N==K){
        printf("0\n");
        return;
    }
    Step[N]=0;
    q[front++]=N;
    visit[N]=true;
    int now;
    int NOW[3];
    while(front!=rear){
        now=q[rear++];
        NOW[0]=2*now;
        NOW[1]=now+1;
        NOW[2]=now-1;
        for(int i=0;i<3;i++){
            if(NOW[i]>=0&&NOW[i]<=100000&&!visit[NOW[i]]){
                if(NOW[i]==K){
                    printf("%d\n",Step[now]+1);
                    return;
                }
                visit[NOW[i]]=true;
                Step[NOW[i]]=Step[now]+1;
                q[front++]=NOW[i];
            }
        }
    }   
}
int main(){
    scanf("%d %d",&N,&K);
    BFS();
}