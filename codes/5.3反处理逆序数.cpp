#include<iostream>
using namespace std;
bool flag[10];
void fun(int *a,int N)
{
	int c;
	for(int i=N-1;i>=0;i--)
	{
		c=0;
		for(int j=0;j<i;j++)
		if(a[j]<a[i])
		c++;
		a[i]=c; 
	}
}
int findmax(int *a,int st,int N)
{
	int MAX=a[st];
	int record;
	for(int i=st+1;i<N;i++)
	{
		if(flag[i]&&a[i]>MAX)
		{
		MAX=a[i];
		record=i;
	    }
	}
	flag[record]=0;
	return MAX;
}
void afun(int *a,int N)
{
	a[N-1]=a[N-1]+1;
	for(int i=N-2;i>=0;i--)
	{
		for(int t=0;t<N;t++)
		flag[t]=1;
		a[i]=a[i]+N-i;
		for(int j=i+1;j<N;j++)
		{
			if(findmax(a,j,N)>=a[i])
			a[i]--;
		}
	}
}
void show(int *a,int N)
{
   for(int i=0;i<N;i++)
	cout<<a[i]<<' ';
	cout<<endl;	
}
int main()
{
	while(1)
	{
	
	int N;
	cin>>N;
	
	int a[N];
	for(int i=0;i<N;i++)
	{
	cin>>a[i];
    }
	fun(a,N);
	show(a,N);
	afun(a,N);
	show(a,N);
	
	
    }
	return 0;
 } 
