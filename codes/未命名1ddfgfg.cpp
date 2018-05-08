#include<iostream>
using namespace std;
void show(int N,int i)
{
	for(int j=0;j<N-i;j++)
	cout<<' ';
	for(int j=0;j<2*i-1;j++)
	cout<<'*';
	cout<<endl;
	if(i!=N)
	show(N,i+1);
	if(i!=N)
	{
		for(int j=0;j<N-i;j++)
	cout<<' ';
	for(int j=0;j<2*i-1;j++)
	cout<<'*';
	cout<<endl;
	 } 
 } 
 int main()
 {

    int N;
    while(cin>>N)
    {
    	show(N,1);
	}
 }
