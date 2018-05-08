#include<iostream>
using namespace std;
const int N=5;
int main()
{
	int a[N]={2,1,4,3,5};
	int i,j,c,flag[N],sum,found;
	for(i=N-1;i>=0;i--)
	{
		c=0;
		for(j=0;j<i;j++)
		if(a[j]<a[i])
		c++;
		a[i]=c;
	}
	for(i=0;i<=N-1;i++)
	flag[i]=1;
	
	
	for(i=N-1;i>=0;i--)
	{
		sum=0;
		j=0;
		found=0;
		while(j<N&&!found)
		{
			sum+=flag[j];
			if(sum==a[i]+1)
			{
				flag[j]=0;
				found=1;
			}
			else
			j++;
		}
		a[i]=j+1;
	}
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<' ';
	}
 } 
