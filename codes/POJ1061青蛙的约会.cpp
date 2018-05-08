#include<iostream>
using namespace std;
long long n[3];
long long mn; 
long long gcd(long long a,long long b){//注意a必须比b大 
	if(b<0)
	b=-b;
	long long t;
	n[0]=0;
	n[1]=1;
	int now=2;
	int last=1;
	int llast=0;
	long long r; 
	while(a%b!=0){
		r=a/b;
		n[now]=n[llast]-r*n[last];
		t=a%b;
		a=b;
		b=t;
		now=(now+1)%3;
		llast=(llast+1)%3;
		last=(last+1)%3;
	}
	mn=n[last];
	return b;
}
int main(){
	long long x,y,m,n,L;
	while(cin>>x>>y>>m>>n>>L){
		long long d=gcd(L,m-n);
		if((y-x)%d==0){
			if(m-n<0){
					cout<<((x - y) / d * mn % L + L) % L<<endl;
			}
			else{
					cout<<((y - x) / d * mn % L + L) % L<<endl;
			}
		}
		else{
			cout<<"Impossible"<<endl;
		}
	}	
}
