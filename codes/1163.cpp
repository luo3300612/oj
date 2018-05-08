#include<iostream>
#include<algorithm> 
using namespace std;
#define MAX 101 
int D[MAX][MAX];

int n;

int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++){
			cin>>D[i][j];
		}
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++){
			D[i][j]=D[i][j]+max(D[i+1][j],D[i+1][j+1]);
		}
	
	cout<<D[1][1]<<endl;
	return 0;
} 
