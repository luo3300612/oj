#include<iostream>
using namespace std;
long power(int a,int b)
{
	int t=a;
	for(int i=1;i<b;i++)
	a=a*t;
	return a;
}
long pd(long N)
{
	long count=1;
	int w;
	for(int i=2;i*i<=N;i++)
	if(i==2)
	for(int j=2;;j++)
	{
		if(power(i,j)<=N)
		count++;
		else
		{
			w=j;
			break;
		}
	}
	else
	for(int j=w;;j--)
	{
	     if(power(i,j)<=N)
		 {
		 count+=j-1;
		 w=j;
		 break;
	     }	
	}
	return count;
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int a;
		cin>>a;
		cout<<pd(a)<<endl;
	}
}
