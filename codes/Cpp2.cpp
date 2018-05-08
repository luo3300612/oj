#include<iostream>
#include"stonewt.h"
using namespace std;
int main()
{
	Stonewt A(1,2),B(3,4);
	cout<<A+B<<endl;
	cout<<B-A<<endl;
	if(A<B)
		cout<<"A<B"<<endl;
	return 0;
}