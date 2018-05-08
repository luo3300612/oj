#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;
int cifang(int t)
{
	int k=1;
	for(int i=0;i<t;i++)
	   k=k*10;
	return k;
}
int zhuanhuan(char *p)
{
	int N=15;
     for(int i=0;i<N;i++)
	    if(*(p+i)=='-')
		   {strcpy(p+i,p+i+1);N--;}
     for(int i=0;i<7;i++)
	    if(*(p+i)=='A'||*(p+i)=='B'||*(p+i)=='C')
		    *(p+i)='2';
		else if(*(p+i)=='D'||*(p+i)=='E'||*(p+i)=='F')
		    *(p+i)='3';
		else if(*(p+i)=='G'||*(p+i)=='H'||*(p+i)=='I')
		    *(p+i)='4';
		else if(*(p+i)=='J'||*(p+i)=='K'||*(p+i)=='L')
		    *(p+i)='5';
		else if(*(p+i)=='M'||*(p+i)=='N'||*(p+i)=='O')
		    *(p+i)='6';
		else if(*(p+i)=='P'||*(p+i)=='R'||*(p+i)=='S')
		    *(p+i)='7';
		else if(*(p+i)=='T'||*(p+i)=='U'||*(p+i)=='V')	
		    *(p+i)='8';
		else if(*(p+i)=='W'||*(p+i)=='X'||*(p+i)=='Y')
		    *(p+i)='9';
	int result=0;
	for(int i=0;i<7;i++)
	   result+=((int)*(p+i)-48)*cifang(6-i);
	return result;
	
 } 
 
 
 
 int main()
 {
 	int number,*a,*c;
 	cin>>number;
 	c=new int[number];
	a=new int[number];
	char p[16];
 	for(int i=0;i<number;i++)
 	   {
		cin>>p;
		c[i]=zhuanhuan(p);
		a[i]=1;	
	   }
	sort(c,c+number);
	int flag=0;
	for(int i=0;i<number;)
	  {
	  for(int j=i+1;j<number;j++)
	      if(c[i]==c[j])
	      {
	      	a[i]++;
	      }
	      else
	      break;
	    if(a[i]!=1)
	   {cout<<c[i]/10000<<'-'<<c[i]%10000<<' '<<a[i]<<endl;flag=1;}
	   i+=a[i];
	  }
	  if(!flag)
	  cout<<"No duplicates."<<endl;
	 return 0;
}
