#ifndef complex_H_
#define complex_H_
#include<iostream>
using namespace std;
class complex
{
private:
	double r;
	double i;
public:
	complex(double,double);
	complex();
	complex operator+(const complex &t)const;
	complex operator-(const complex &t)const;
	complex operator*(const complex &t)const;
	complex operator*(double mult)const;
	complex operator~()const;
	friend complex operator*(double mult,const complex &t)
	{return t*mult;}
	friend ostream &operator<<(ostream &os,complex &t)
	{os<<"( "<<t.r<<" , "<<t.i<<" ) "<<endl;return os;}
	friend istream &operator>>(istream &is,complex &t)
	{
		cout<<"real:"<<endl;
		is>>t.r;
		cout<<"imaginary:"<<endl;
		is>>t.i;
		return is;
	}
	
};
#endif