#include<iostream>
using namespace std;
int main()
{
	cout<<"���ۼ���"<<endl;
	cout<<"1.�����"<<endl;
	cout<<"2.ģ����"<<endl;
	int N;
	cin>>N;
	if(N==1)
	{
	
	cout<<"x*y==1(mod k)"<<endl;
	cout<<"Y:";
	int x,y,k;
	cin>>y;
	cout<<"k:";
	cin>>k;
	for(int i=0;;i++)
	if((y*i-1)%k==0)
	   {cout<<"x="<<i;break;}
    }
    else if(N==2)
    {
    	int x,y;
    	cin>>x>>y;
    	
    	cout<<endl;
    	cout<<x%y<<endl;
	}
	return 0;
 } 
