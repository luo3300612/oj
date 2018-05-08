#include<iostream>
using namespace std;
int N;
int d[101][201];
int main(){
	cin>>N;
	while(N){
		for(int i=1;i<=N;i++){
			cin>>d[i][0];
			for(int j=1;j<=2*d[i][0];j++)
				cin>>d[i][j]; 
		}
		
	}
	
} 
