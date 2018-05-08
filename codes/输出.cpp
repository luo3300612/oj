#include<iostream>
#define cen 10
#define bc 2
using namespace std;
int main(){
	for(double i=1;i<=cen*2*bc;i++){
	 double t=i/bc*i/bc-2*cen*i/bc+cen*cen;
	 for(int j=1;j<=t;j++)
	 cout<<' ';
	 cout<<'*'<<endl;
	} 
} 
