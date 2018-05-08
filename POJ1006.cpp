#include<iostream>
using namespace std;
int reverse(int a,int b)
{
	for(int i=1;;i++)
	if((a*i-1)%b==0)
	  return i;
}
int solution(int a,int b,int c,int N)
{
	int X,M,M1,M2,M3,y1=1,y2=1,y3=1;
	M1=28*33;
	M2=23*33;
	M3=23*28;
    if(M1) 
	y1=reverse(M1,23);
    if(M2)
	y2=reverse(M2,28);
	if(M3)
	y3=reverse(M3,33);
	X=(a*M1*y1+b*M2*y2+c*M3*y3)%21252-N;
	if(X<0)
	return X+21252;
	else if(X==0)
	return 21252;
	else
	return X;
	
}
int main()
{
	int a,b,c,N;
	int i=0;
	cin>>a>>b>>c>>N;
	while(a!=-1)
	{
		i++;
		cout<<"Case "<<i<<": the next triple peak occurs in "<<solution(a,b,c,N)<<" days."<<endl;
		cin>>a>>b>>c>>N;
	}
	return 0;
}
