#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int m,n;
		cin>>m>>n;
		int count=0;
		for(int i=1;i<=m;i++)
		{
			if(i%7==0)
			count++;
			else if(i%10==7||i/10==7)
			count++;
			else
			{
				int t=i;
				int sum=0;
				do
				{
					sum=sum+t%10;
					t=t/10;
				}while(t);
				if(sum%7==0||sum%10==7||sum/10==7)
				count++;
			}
			
		}
		m=m-count;
		int result=1;
		for(int i=0;i<n;i++)
		result=(m-i)*result;
		for(int j=1;j<=n;j++)
		result=result/j;
		cout<<result<<endl;
	}
}
