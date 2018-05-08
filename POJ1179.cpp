#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 51
int number[MAX];
char op[MAX];
int maxScore[MAX][MAX];
int minScore[MAX][MAX]; 
int N;
int dp(int i,int j){
	
}
void move(int t,int &len,int time){
	char oper=op[t];
	strcpy(op+t-1,op+t);

	if(op[t]=='t'){
		printf("进入+操作\n");
		if(t==1){
			if(time)
			number[len]=number[1]+number[len];
			for(int i=1;i<=len-1;i++){
				number[i]=number[i+1];
			}
			len--;
		}
		else{
			number[t]=number[t-1]+number[t];
			for(int i=t-1;i<=len-1;i++){
				number[i]=number[i+1];
			}
			len--;
		}
	}
	else if(op[t]=='x'){
		printf("进入×操作\n");
		if(t==1){
			number[len]=number[1]*number[len];
			for(int i=1;i<=len-1;i++){
				number[i]=number[i+1];
			}
			len--;
		}
		else{
			number[t]=number[t-1]*number[t];
			for(int i=t-1;i<=len-1;i++){
				number[i]=number[i+1];
			}
			len--;
		}
	}
	printf("结束操作\n");
}
void print(){
	for(int i=1;op[i]!='\0';i++){
		printf("%c ",op[i]);
		printf("%d ",number[i]);
	}
	printf("\n");
	for(int i=1;op[i]!='\0';i++){
		printf("%d    ",i);
	}
	printf("\n");
}
inline int index(int i){
	if(i==0)return N;
	else return i;
}
int main(){
	char useless;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%c%c",&useless,&op[i]);
		scanf("%d",&number[i]);
	}
	for(int i=1;i<=N;i++){
		if(op[i]=='t'){
			maxScore[i][i]=number[i]+number[index(i-1)];
			minScore[i][i]=number[i]+number[index(i-1)];
		}
		else{
			maxScore[i][i]=number[i]*number[index(i-1)];
			minScore[i][i]=number[i]*number[index(i-1)];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			if(i==j){continue;}
			if(op[j]=='t'){
				maxScore[i][j]=maxScore[i][index(j-1)]+number[j];
				minScore[i][j]=minScore[i][index(j-1)]+number[j];
			} 
		}
	}
}
/*
4
t -7 t 4 x 2 x 5
*/
 
