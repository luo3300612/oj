#include<iostream>
using namespace std;
int main()
{
	long N;
	while(cin>>N)
	{
		long sum=0;
		for(long i=1;;i++)
		{
			sum+=N%3;
			N/=3;
			if(N==0)
			break;
		}
		cout<<sum<<endl;
	}
	return 0;
}
