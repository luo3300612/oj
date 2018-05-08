#include<iostream> 
using namespace std;
int main()
{
	long N;
	cin>>N;
	int *a;
	a=new int[N];
	int max;
	for(long i=0;i<N;i++)
	{
		cin>>a[i];
		if(i==0)
		max=a[i];
		if(a[i]>max)
		max=a[i];
	}
	long times;
	cin>>times;
	while(times--)
	{
		long d,b;
		cin>>d>>b;
		a[d]=b;
		if(b>max)
		{
		cout<<b<<endl;
		continue;
	    }
		max=a[0];
		for(long i=1;i<N;i++)
		{
			if(a[i]>max)
		    max=a[i];
		}
		cout<<max<<endl;
	}
	return 0;
}
