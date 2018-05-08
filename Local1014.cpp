#include<iostream>
using namespace std;
void change(char s[][5],int n,int i,int j)
{
	s[i][j]='A';
	for(int t=i+1;t<n;t++)
	{
		if(s[t][j]!='X')
		s[t][j]='A';
		else
		break;
	}
	for(int t=i-1;t>=0;t--)
	{
		if(s[t][j]!='X')
		s[t][j]='A';
		else
		break;
	}
	for(int t=j+1;t<n;t++)
	{
		if(s[i][t]!='X')
		s[i][t]='A';
		else
		break;
	}
	for(int t=j-1;t>=0;t--)
	{
		if(s[i][t]!='X')
		s[i][t]='A';
		else
		break;
	}
 } 
 int main()
 {
 	char s[][5]={"0000","1X11","2222","3333"};
 	for(int i=0;i<4;i++)
 	cout<<s[i]<<endl;
 	while(1)
 	{
 		int x,y;
 		cin>>x>>y;
 		change(s,4,x,y);
 			for(int i=0;i<4;i++)
 	cout<<s[i]<<endl;
	 }
 }
