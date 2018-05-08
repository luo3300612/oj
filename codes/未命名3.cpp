#include<iostream>
#include<cstring>
using namespace std;
void standard(char *p)
{
	for(int i=0;i<15;i++)
	{
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
    } 
    for(int i=0;i<15;i++)
    {
		if((int)*(p+i)<=57&&(int)*(p+i)>=48)
			;
		else
		{strcpy(p+i,p+i+1);}
	}
	*(p+7)=*(p+6);
	*(p+6)=*(p+5);
	*(p+5)=*(p+4);
	*(p+4)=*(p+3);
	*(p+3)='-';
	*(p+8)='\0';
}
int main()
{
	int N;
	cin>>N;
	int *a,*b,*c;
	a=new int[N];
	b=new int[N];
	c=new int[N];
	for(int i=0;i<N;i++)
	a[i]=0;
	char **p1,**p2;
	p1=new char*[N];
	p2=new char*[N];
	for(int j=0;j<N;j++)
	  {
	  p1[j]=new char[16];
	  p2[j]=new char[16];
      }
	  for(int j=0;j<N;j++)
	  {
	  	cin>>p1[j];
	  	standard(p1[j]);
	  }
	  int m=0;
	  int mm=0;
	  for(int j=0;j<N;j++)
	    c[j]=-1;
	for(int j=0;j<N;j++)
	{
		for(int i=0;i<N;i++)
		{
			if(j==c[i])
			{
				j++;
				i=0;
			}
		 } 
	for(int k=j+1;k<N;k++)
	{
	
	  for(int i=0;i<8;i++)
	  {
	  	if(p1[j][i]!=p1[k][i])
	  	break;
	  	else if(i==7)
	  	{
		  a[j]++;
		  c[mm]=k;
		  mm++;
		  
	    }
	    
	  }
	 
    }
     if(a[j])
	    {
	    
		p2[m]=p1[j];
		b[m]=a[j]+1;
		m++;
	    }
   }
   int x=0;
   for(int t=0;t<N;t++)
   if(a[t])
   x++;

   
  
     int change;
	 for(int j=0;j<x-1;j++)
	 for(int i=0;i<x-1-j;i++)
	     {
	     	if(strcmp(p2[i],p2[i+1])>0) 
	     	{
	     		p1[0]=p2[i];
	     		p2[i]=p2[i+1];
	     		p2[i+1]=p1[0];
	     		change=b[i];
	     		b[i]=b[i+1];
	     		b[i+1]=change;
			 }
		  } 
	  if(x)
	for(int j=0;j<x;j++)
	    cout<<p2[j]<<' '<<b[j]<<endl;
	else
	 cout<<"No duplicates."	;
      delete []p1;
      delete []p2;
		return 0;
}
