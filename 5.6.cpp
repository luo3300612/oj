#include<iostream>
using namespace std;
int a[100][100];
int pd(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		for(int t=0;t<m;t++)
		for(int l=0;l<n;l++)
		if(!(t==i&&j==l)&&a[i][j]==a[t][l])
		return 1;
	return 0;
}
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		if(pd(a,m,n))
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
 } 
