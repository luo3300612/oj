#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N)
	{
		char *p,*p1;
		p=new char[2*N];
		p1=new char[2*N];
		for(int i=0;i<=N-1;i++)
		p[i]='0';
		for(int j=N;j<2*N;j++)
		p[j]='1';
		for(int i=2;;i++)
		{
			//cout<<"i="<<i<<endl;
			delete []p1;
			p1=new char[2*N];
			int number=0;
			int now=0;
			strcpy(p1,p);
			int nowl=2*N;
			while(number!=N)
			{
				//cout<<p1<<endl;
				now+=i-1;
				if(now>nowl-1)
					{
						now=now%nowl; 
					}
				if(p1[now]=='0')
				{//cout<<"now="<<now<<endl;
				break;}
				else
				{
					strcpy(p1+now,p1+now+1);
					
					nowl--;
					number++;
				}
			}
			if(number==N)
			{
			cout<<i<<endl;
			break;
		    }
			
		}
		delete []p1;
		cin>>N;
	}
 } 
