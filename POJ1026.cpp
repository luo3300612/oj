#include<iostream>
#include<cstring>
using namespace std;
void encode(char *p1,int a[],int times,int N)
{
	char *p2;
	p2=new char[N+1];
	
	strcpy(p2,p1);
	while(times--)
	{
		for(int i=0;i<N;i++)
		{
			*(p1+a[i]-1)=*(p2+i);
		}
		strcpy(p2,p1);
	}
}
int main()
{
	int N;
	int *a;

	char *p;
	cin>>N;
	while(N)
	{
	a=new int[N];
	
	for(int i=0;i<N;i++)
		cin>>a[i];
	int t;
	cin>>t;
	cin.get();
	do
	{

		p=new char[N+1];
		cin.getline(p,N);
		for(int j=0;j<N+1;j++)
			if(*(p+j)=='\0'||!isalpha(*(p+j)))
				*(p+j)=' ';
		encode(p,a,t,N);
		*(p+N)='\0';
		cout<<p;
		cin>>t;
		cin.get();
		delete []p;

	}while(t);
	delete []a;
	cin>>N;
	}

	return 0;
}
