#include<iostream>
using namespace std;
int power(int x,int n)
{
	if(n/2)
	{ 
	int c=power(x,n/2); 
	return c*c*power(x,n%2);
	} 
	else if(n==1)
	return x;
	else
	return 1;
 } 
 int main()
 {
 	int x;
 	cin>>x;
 	while(x)
 	{
 		int N;
 		cin>>N;
 		cout<<power(x,N)<<endl;
 		cin>>x;
	 }
 }
