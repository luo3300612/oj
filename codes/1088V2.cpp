/*
DP¼ÇÒä»¯ËÑË÷ 
*/ 
#include<iostream>
using namespace std;
#define MAX 102
int D[MAX][MAX];
int rec[MAX][MAX];
int row,col;
int max(int w,int x,int y,int z){
	int mx=0;
	if(w>mx)
	mx=w;
	if(x>mx)
	mx=x;
	if(y>mx)
	mx=y;
	if(z>mx)
	mx=z;
	return mx;
}
int DFS(int i,int j){
	if(rec[i][j]!=-1)
		return rec[i][j];
	
	if(D[i][j]<D[i-1][j]&&D[i][j]<D[i+1][j]&&D[i][j]<D[i][j+1]&&D[i][j]<D[i][j-1]){
		rec[i][j]=1;
		return 1;
	}
		
	int m1,m2,m3,m4;
	m1=m2=m3=m4=0;	
	if(D[i][j]>D[i-1][j])
		m1=1+DFS(i-1,j);
		
	if(D[i][j]>D[i+1][j])
		m2=1+DFS(i+1,j);
		
	if(D[i][j]>D[i][j-1])
		m3=1+DFS(i,j-1);
		
	if(D[i][j]>D[i][j+1])
		m4=1+DFS(i,j+1);
	
	rec[i][j]=max(m1,m2,m3,m4);
	return rec[i][j];
}
int main(){
	cin>>row>>col;
	for(int i=0;i<=row+1;i++)
		for(int j=0;j<=col+1;j++){
			if(i==0||j==0||i==row+1||j==col+1){
				D[i][j]=10001;
				continue;
			}
			rec[i][j]=-1;
			cin>>D[i][j];
		}
	int mx=1;
	int now;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			now=DFS(i,j);
			if(now>mx)
			mx=now;	
		}
	}
	cout<<mx<<endl;	
} 
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/

