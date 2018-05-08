#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct point{
	double x;
	double y;
};
struct line
{
	double A;
	double B;
	double C;
};
line aline(point A,point B)
{
	line T; 
	if(A.x!=B.x)
	{
		T.B=A.x-B.x;
		T.A=B.y-A.y;
		T.C=A.y*B.x-A.x*B.y; 
	}
	else if(A.y!=B.y)
	{
		T.A=A.y-B.y;
		T.B=B.x-A.x;
		T.C=A.x*B.y-A.y*B.x; 
	}
	return T;
}
line bline(line T,point A)
{
	line S;
	S.A=T.B;
	S.B=-T.A;
	S.C=-(S.A*A.x+S.B*A.y);
	return S;
}
bool pdLP(line T,point center,double r)
{
	if(fabs(T.A*center.x+T.B*center.y+T.C)/sqrt(T.A*T.A+T.B*T.B)<=r)
	return true;
	else return false;
}
bool pdPP(point A,point B,double r)
{
	if(sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y))<=r)
	return true;
	else
	return false;
}
bool pd(line T,point A,point B)
{
	if((T.A*A.x+T.B*B.x+T.C>=0&&T.A*B.x+T.B*B.y+T.C<=0)||(T.A*A.x+T.B*B.x+T.C<=0&&T.A*B.x+T.B*B.y+T.C>=0))
	return true;
	else
	return false;
}
point X(line T,line S)
{
	point X;
	X.y=(T.B*T.C-T.A*S.C)/(T.A*T.A+T.B*T.B);
	X.x=-(T.A*T.C+T.B*S.C)/(T.A*T.A+T.B*T.B);
	return X;
}
point end(line T,point start,double r,point fangxiang)
{
	point A,B;
	if(T.A!=0)
	{
		A.y=r/sqrt(T.B*T.B/T.A/T.A+1)+start.y;
		B.y=-r/sqrt(T.B*T.B/T.A/T.A+1)+start.y;
		A.x=-(T.B*A.y+T.C)/T.A;
		B.x=-(T.B*B.y+T.C)/T.A;
	}
	else if(T.B!=0)
	{
		A.x=r/sqrt(T.A*T.A/T.B/T.B+1)+start.x; 
		B.x=-r/sqrt(T.A*T.A/T.B/T.B+1)+start.x;
		A.y=-(T.C+T.A*A.x)/T.B;
		B.y=-(T.C+T.A*B.x)/T.B; 
	}
	if((A.x-start.x)*fangxiang.x>=0&&(A.y-start.y)*fangxiang.y>=0)
	return A;
	else
	return B;
}
void show(const line &T)
{
	cout<<T.A<<"x+"<<T.B<<"y+"<<T.C<<"=0"<<endl;
}
int main()
{
	point A={0,0},B={0,1},C={0,4},D={5,0},E={1,0};
	line T,S;
	T=aline(A,B);
	S=bline(T,C);
	show(T);
	point m=X(T,S);
	cout<<end(T,A,3,E).x<<' '<<end(T,A,3,E).y<<endl;
	if(pdLP(T,C,2))
	{
		cout<<1<<endl;
		if(pdPP(A,m,3))
		cout<<"Yes"<<endl;
		else if(pdPP(end(T,A,3,E),C,2))
		cout<<"Yes"<<endl;
		else
		cout<<"Miss"<<endl;
	}
	else
	cout<<"Miss"<<endl;
}


