#include<iostream>
const int W=7; 
using namespace std;
void tra(int n)
{
	int t=n%W;
	n=n/W;
	if(n)
	tra(n);
	cout<<t;
}
int main()
{
	int N;
	cin>>N;
	while(N)
	{
		tra(N);
		cin>>N;
	}
}
