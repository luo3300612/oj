#include<iostream>
#include<cmath>
using namespace std;
double fx(double x)
{
	return sin(x)/x-0.5;
}
int main()
{
	
	double down=3.14/2;
	double up=3.14;
	double x=(down+up)/2;
	do
	{

		if(fx(x)>0)
		{
			down=x;
			x=(down+up)/2;
		}
		else
		{
			up=x;
			x=(down+up)/2;
		}
	}while(fabs(fx(x))>=1e-10);

	cout.precision(8);
	cout.setf(ios_base::fixed);
	cout<<x;
}
