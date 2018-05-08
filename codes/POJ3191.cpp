#include<iostream>
using namespace std;
int trans(int number,int *a,int i)
{
	if(number%2==0)
	{
		a[i]=0;
		number=number/-2;
	}
	else
	{
		a[i]=1;
		number=(number-1)/-2;
	}
	if(number!=0)
	trans(number,a,i+1);
	else
	return i;
}
int main()
{
	int number=0;
	while(cin>>number)
	{
		int sum=0;
		int a[1005];
		int t=trans(number,a,0) ;
		for(int i=t;i>=0;i--)
		cout<<a[i];
		cout<<endl;
   }

	return 0;
	
} 
