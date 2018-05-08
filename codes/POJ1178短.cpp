#include<stdio.h>
#include<memory.h>
#include<queue>
#include<math.h>
using namespace std;
#define MAX 9
int step[MAX][MAX][65];
int stepMark[65];
int king[MAX][MAX];
int dp[MAX][MAX][64];
int nowMatrix[MAX][MAX];
int preKnight[MAX][MAX];
queue<int> q;
int knightMove[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};
inline bool realPos(int x,int y){
	if(x<=8&&x>=1&&y<=8&&y>=1){return true;}
	else{return false;}
}
void calStep(int x,int y){
	int num=(x-1)*8+y;
	if(stepMark[(x-1)*8+y]){return;}
	q.push((x-1)*8+y);
	stepMark[(x-1)*8+y]=1;
	step[x][y][(x-1)*8+y]=0;
	int nowX,nowY,nowQ,nextX,nextY,Q;
	while(!q.empty()){
		Q=q.front();
		q.pop();
		nowX=(Q-1)/8+1;
		nowY=Q-(nowX-1)*8;
		for(int i=0;i<=7;i++){
			nextX=nowX+knightMove[i][0];
			nextY=nowY+knightMove[i][1];
			if(realPos(nextX,nextY)){
				if(step[nextX][nextY][num]==-1){
					step[nextX][nextY][num]=step[nowX][nowY][num]+1;
					q.push((nextX-1)*8+nextY);
				}
			}
		}
	}
}
int transX(char t){
	return '9'-t;
}
int transY(char t){
	return t-'A'+1;
}
int main(){
	memset(step,-1,sizeof(step));
	memset(stepMark,0,sizeof(stepMark));
	memset(preKnight,0,sizeof(preKnight));
	char str[129];
	scanf("%s",&str);
	char X,Y;
	int count=0;
	int x,y;
	int minN=9999999;
	while(str[count]!='\0'){
		minN=9999999;
		X=str[count++];
		Y=str[count++];
		x=transX(Y);
		y=transY(X);
		if(count==2){
			for(int i=1;i<=MAX-1;i++){
				for(int j=1;j<=MAX-1;j++){
					king[i][j]=abs(x-i)+abs(y-j);
					dp[i][j][0]=king[i][j];
				}
			}
		}
		else{
			int deep=count/2-1;
			calStep(x,y);
			int num=(x-1)*8+y;
			for(int m=1;m<=MAX-1;m++){
				for(int n=1;n<=MAX-1;n++){
					calStep(m,n);
					int num2=(m-1)*8+n;
					for(int i=1;i<=MAX-1;i++){
						for(int j=1;j<=MAX-1;j++){
							if(m==1&&n==1){
								nowMatrix[i][j]=step[i][j][num2]+king[m][n]+step[m][n][num];
							}
							else{
								if(nowMatrix[i][j]>step[i][j][num2]+king[m][n]+step[m][n][num]){
									nowMatrix[i][j]=step[i][j][num2]+king[m][n]+step[m][n][num];
								}
							}
						}
					}
				}
			} 
			for(int i=1;i<=MAX-1;i++){
				for(int j=1;j<=MAX-1;j++){
					if(count==4){
						dp[i][j][deep]=nowMatrix[i][j];
					}
					else{
						dp[i][j][deep]=min(step[i][j][num]+dp[i][j][deep-1],nowMatrix[i][j]+preKnight[i][j]);
					}
					if(dp[i][j][deep]<minN){
						minN=dp[i][j][deep];
					}
				}
			}
			for(int i=1;i<=MAX-1;i++){
				for(int j=1;j<=MAX-1;j++){
					preKnight[i][j]=preKnight[i][j]+step[i][j][num];
				}
			}
		}	
	}
	if(count==2){printf("0");}
	else{printf("%d",minN);}
} 
