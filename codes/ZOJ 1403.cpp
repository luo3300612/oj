#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int power(int a,int i)
{
	int b=a;
	for(int t=1;t<i;t++)
	    a=a*b;
	return a;
}
int main()
{
	char p[26];
	int a[26]={0};
	int t;
	while(cin>>t>>p)
	{
		if(t==0&&strcmp(p,"END")==0)
		break;
		int lena=strlen(p);
		for(int i=0;i<strlen(p);i++)
		{
			a[i]=(int)p[i]-64;
		}
		sort(a,a+lena);
		int b,c,d,e,f,flag=0;
		for(int i=0;i<lena;i++)
		   for(int j=0;j<lena;j++)
		   if(i!=j)
		       for(int k=0;k<lena;k++)
		       if(i!=k&&j!=k)
		          for(int l=0;l<lena;l++)
		          if(i!=l&&j!=l&&k!=l)
		              for(int m=0;m<lena;m++)
		              if(i!=m&&j!=m&&k!=m&&l!=m)
		                  if(power(a[i],1)-power(a[j],2)+power(a[k],3)-power(a[l],4)+power(a[m],5)==t)
		                  {
		                  	b=i;
		                  	c=j;
		                  	d=k;
		                  	e=l;
		                  	f=m;
		                  	flag=1;
						  }
		if(flag==0)
		cout<<"no solution"<<endl;
		else
		{
			cout<<(char)(a[b]+64)<<(char)(a[c]+64)<<(char)(a[d]+64)<<(char)(a[e]+64)<<(char)(a[f]+64)<<endl;
		}
		char p[26];
	    int a[26]={0};
	    int t;	
		flag=0;			  
	}
 } 
