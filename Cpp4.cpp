#include<iostream>
#include"H1.h"
using namespace std;
complex::complex(double a,double b)
{
	r=a;
	i=b;
}
complex::complex()
{
	r=i=0;
}
complex complex::operator+(const complex &t)const
{
	complex sum;
	sum.r=r+t.r;
	sum.i=i+t.i;
	return sum;
}
complex complex::operator-(const complex &t)const
{
	complex diff;
	diff.r=r-t.r;
	diff.i=i-t.i;
	return diff;
}
complex complex::operator*(const complex &t)const
{
	complex result;
	result.r=r*t.r-i*t.i;
	result.i=r*t.i+t.r*i;
	return result;
}	
complex complex::operator*(double mult)const
{

	complex result;
	result.r=r*mult;
	result.i=i*mult;
	return result;
}
complex complex::operator~()const
{
	complex result;
	result.r=r;
	result.i=-i;
	return result;
}