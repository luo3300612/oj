#include<iostream>
using namespace std;
#include "H1.h"
int main()
{
	complex a(3.0,4.0);
	complex c;
	cout<<"Enter a complex number (q to quit):\n";
	while(cin>>c)
	{
		cout<<"c is "<<c<<'\n';
		cout<<"complex conjugate is "<<~c<<endl;
		cout<<"a is "<<a<<endl;
		cout<<"a + c is "<<a+c<<endl;
		cout<<"a - c is "<<a-c<<endl;
		cout<<"a * c is "<<a*c<<endl;
		cout<<"2 * c is "<<2*c<<'\n';
		cout<<"Enter a complex number(q to quit)"<<endl;
	}
	cout<<"Done!\n";
	return 0;
}