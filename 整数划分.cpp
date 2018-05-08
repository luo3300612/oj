#include<iostream>
using namespace std;
int q(int n,int m)
{
	if((n<1)||(m<1))
		return 0;
	if((n==1)||(m==1))
		return 1;
	if(n<m)
		return q(n,n);
	if(n==m)
		return q(n,m-1)+1;
	return q(n,m-1)+q(n-m,m);
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int a;
		cin>>a;
		cout<<q(a,a)<<endl;
	}
	return 0;
}
