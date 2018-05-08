#include<iostream>
#include<cstring>
using namespace std;
int main()
{

double a=1;
int t=10;
while(t--)
{
	a*=10;
	cout.setf(ios::fixed);
	cout<<a<<endl;
}
	
	return 0;
 } 
