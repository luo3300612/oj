#ifndef DTONEWT_H_
#define STONEWT_H_
#include<iostream>
using namespace std;
class Stonewt
{
private:
	enum{Lbs_per_stn=14};
	int stone;
	double pds_left;
	double pounds;
	int state;
public:
	Stonewt(double lbs);
	Stonewt(int stn,double lbs);
	Stonewt();
	~Stonewt();
	Stonewt operator+(const Stonewt & t)const;
	Stonewt operator-(const Stonewt & t)const;
	friend ostream &operator<<(ostream & os,const Stonewt & t)
		{
	if(t.state==1)
        os<<t.stone<<" stone, "<<t.pds_left<<" pounds\n";
	else
		os<<t.pounds<<" pounds\n";
	return os;
	}
	bool operator<(const Stonewt &t)const;

};
#endif