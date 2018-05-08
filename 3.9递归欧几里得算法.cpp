#include<iostream>
using namespace std;
int cal(int a,int b)
{
	if(a<b)
	return cal(b,a);
	if(b==0)
	return a;
	else
	return cal(a%b,b); 
}
int main()
{
	cout<<cal(121,11)<<endl;
}
