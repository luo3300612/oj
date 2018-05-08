#include<iostream>
#include<math.h>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int rec[MAX][MAX];
int row,col;
int mx=1;
int cal(int i,int j){
	/*if(rec[i][j]!=-1)
	return rec[i][j];*/
	if(1){
		if(D[i][j]<D[i][j+1]&&D[i][j]<D[i][j-1]&&D[i][j]<D[i+1][j]&&D[i][j]<D[i-1][j]){
			rec[i][j]=1;
			return rec[i][j];
		}
		else{
			if(D[i][j]>D[i-1][j]){
				rec[i][j]=1+max(rec[i][j],rec[i-1][j]);
			}
			if(D[i][j]>D[i+1][j]){
				rec[i][j]=1+max(rec[i][j],rec[i+1][j]);
			}
			if(D[i][j]>D[i][j-1]){
				rec[i][j]=1+max(rec[i][j],rec[i][j-1]);
			}
			if(D[i][j]>D[i][j+1]){
				rec[i][j]=1+max(rec[i][j],rec[i][j+1]);
			}
			if(rec[i][j]>mx)
			mx=rec[i][j];
			return rec[i][j];
		}
	}
}
int main() {
	int row,col;
	cin>>row>>col;
	for(int i=0;i<=row+1;i++)
		for(int j=0;j<=col+1;j++){
			
			if(i==0||j==0||i==row+1||j==col+1){
				rec[i][j]=0;
				D[i][j]=10001;
				continue;
			}
			cin>>D[i][j];
			rec[i][j]=-1;
		}
			
			
	for(int i=1;i<=row;i++)
		for(int j=1;j<=col;j++){
			cal(i,j);
		}
		
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			cout<<rec[i][j]<<' ';
		}
		cout<<endl;
	}
			
		
	
	cout<<mx;
}
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
