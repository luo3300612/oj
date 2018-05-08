#include<iostream>
#include<math.h>
using namespace std;
#define MAX 1000
int D[MAX];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>D[i];
	}
	int now=1;
	int mx=0;
	for(int i=2;i<=n;i++){
		if(D[i]>D[i-1]){
			now++; 
			mx=max(mx,now);
		 } 
		
		else{
			mx=max(mx,now);
			now=1;
		}
		
	}
	cout<<mx<<endl;
}
//1 7 3 5 9 4 8
