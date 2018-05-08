#include<iostream>
#include <cstring>
#define MAX 101
int shortestRoute[MAX][MAX];
int n;
using namespace std;
void myFloyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		if(shortestRoute[i][k]!=10000)
			for(int j=1;j<=n;j++){
				if(shortestRoute[k][j]!=10000)
					if(shortestRoute[i][j]>shortestRoute[i][k]+shortestRoute[k][j]){
						shortestRoute[i][j]=shortestRoute[i][k]+shortestRoute[k][j];
					}
			}
}
int main(){
	cin>>n;
	while(n!=0){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j){
				shortestRoute[i][j]=0;
				continue;
			}
			shortestRoute[i][j]=10000;
		}
	int num;
	int target;
	int time;
	int count=1;
	while(count<=n){
		cin>>num;
		while(num--){
			cin>>target;
			cin>>time;
			shortestRoute[count][target]=time;
		}
		count++;
	}
	myFloyd();	
	int mx=0;
	int rc;
	int mn=10000;
	for(int i=1;i<=n;i++){
		mx=0;
		for(int j=1;j<=n;j++){
			if(shortestRoute[i][j]>mx){
				mx=shortestRoute[i][j];
			}
		}
		if(mx<mn)
		{
			mn=mx;
			rc=i;
		}
		
	}
	if(mn!=10000)
	cout<<rc<<' '<<mn<<endl;
	else
	cout<<"disjoint"<<endl;
	cin>>n;
	}
}
