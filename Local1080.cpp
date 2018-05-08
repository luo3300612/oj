#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a>b&&a>c)
		{
			if(a*a==b*b+c*c)
			cout<<"Y"<<endl;
			else
			cout<<"N"<<endl;
		}
		else if(b>a&&b>c)
		{
			if(b*b==a*a+c*c)
			cout<<"Y"<<endl;
			else
			cout<<"N"<<endl;
		}
		else
		{
			if(c*c==a*a+b*b)
			cout<<"Y"<<endl;
			else
			cout<<"N"<<endl;
		}
	}
	return 0;
}
