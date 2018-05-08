#include<iostream>
using namespace std;
int T;
int N;
int now[401];
int main(){
	cin>>T;
	int a,b;
	int t;
	int st,ed;
		while(T--){
		cin>>N;
		for(int i=1;i<=400;i++)
			now[i]=0;
			
			while(N--){
			
			cin>>a;
			cin>>b;
			if(a>b){
				t=a;
				a=b;
				b=t;
			}
			if(a%2==0)
				st=a-1;
			else
				st=a;
			if(b%2==0)
				ed=b;
			else
				ed=b+1;
			for(int j=st;j<=ed;j++)
				now[j]++; 
			}
		int M=0;
		for(int i=1;i<=400;i++){
			if(now[i]>M)
			M=now[i];
		}
		cout<<M*10<<endl;
	}
} 
