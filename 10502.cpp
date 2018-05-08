#include<iostream>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int N;
int recn1[MAX][MAX][MAX];
int Ceng[MAX][MAX];
int main(){
	int flag=0;
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			cin>>D[i][j];
		}
	int mx=-99999;
	int now;
	for(int m=1;m<=N;m++){
		for(int n=1;n<=N;n++){
			for(int i=1;i+m-1<=N;i++){
				for(int j=1;j+n-1<=N;j++){
					if(m==1&&n==1){
						recn1[i][j][m]=D[i][j];
						now=D[i][j];
						Ceng[i][j]=now;
						if(now>mx)
						mx=now;
						continue;	
					}
					if(n==1){
						recn1[i][j][m]=recn1[i][j][m-1]+D[i+m-1][j];
						now=recn1[i][j][m];
						if(now>mx)
						mx=now;
						Ceng[i][j]=now;
						continue;
					}
					now=Ceng[][]rec[i][j][m][n-1]+rec[i][n+j-1][m][1];
					else if(Rec[i][j][m-1][n]==1)
					rec[i][j][m][n]=rec[i][j][m-1][n]+rec[i+m-1][j][1][n];
					else
					cout<<"error\n"<<endl;
					
					if(rec[i][j][m][n]>mx)
						mx=rec[i][j][m][n];
					Rec[i][j][m][n]=1;
					
					 
				}
			}
		}
	}
	cout<<mx<<endl;
	
	/* 
	for(int m=1;m<=N;m++){
		for(int n=1;n<=N;n++){
			for(int i=1;i+m-1<=N;i++){
				for(int j=1;j+n-1<=N;j++){
					cout<<rec[i][j][m][n]<<' ';
				}
				cout<<endl;
			}
			cout<<endl<<endl;
		}
	}
	*/ 
} 

/*ÊäÈë
4
0 -2 -7 0 
9 2 -6 2
-4 1 -4 1 
-1 8  0 -2 



*/ 
