#include<iostream>
using namespace std;
const int N=3;
void powerset(char a[],char s[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	cout<<s[i]<<endl;
	cout<<endl;
	for(i=0;i<N;i++)
	{
		for(j=0;j<n;j++)
		if(s[j]==a[i])
		break;
		if(j>=n)
		{
			s[n]=a[i];
			powerset(a,s,n+1);
		}
	}
 } 
 int main()
 {
 	char a[]="asd";
 	char s[]="asd";
 	powerset(a,s,0);
 }
