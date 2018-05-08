#include<iostream>
using  namespace std;
int main(){
	int n;
	while(cin>>n){
		int *p;
		p=new int[n*n];
		for(int i=0;i<n*n;i++){
			cin>>p[i];
		}
		cout<<endl;
		for(int i=0;i<n*n;i++){
			cout<<p[i]<<' '<<endl;
		}
		delete []p;
	}
	return 0;
}
