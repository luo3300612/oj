#include<iostream>
using namespace std;
int judge(char *p,int N)
{
	int sum=0;
	for(int i=0;i<N;i++)
	    for(int j=i+1;j<N;j++)
	    if(p[i]>p[j])
	      sum++;
	return sum;
}
int main()
{
	char **p,*p1;
	int M,N;
	cin>>N>>M;
	p=new char*[M];
	p1=new char[N+1];
	for(int i=0;i<M;i++)
	  {p[i]=new char[N+1];cin>>p[i];}
	int *a,t;
	a=new int[N];
	for(int i=0;i<M;i++)
	    a[i]=judge(p[i],N);
	for(int j=0;j<M-1;j++)
	for(int i=0;i<M-j-1;i++)
	{
		if(a[i]>a[i+1])
		{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			p1=p[i];
			p[i]=p[i+1];
			p[i+1]=p1;
		}
	}
	for(int i=0;i<M;i++)
	cout<<p[i]<<endl;
	for( int i = 0; i < M; i++ )
¡¡¡¡    delete []p[i];
      delete []p;
	return 0;
}
