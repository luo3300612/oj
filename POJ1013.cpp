#include<iostream>
using namespace std;
int pd(char *p,int a[])
{
	int t=0,m;
	for(int i=0;i<19;i++)
	    {
		if(*(p+i)==' ')
	    t++;
	    if(t==2)
	    {
		
		m=i;
		break;
		}
		}
	if(*(p+m+1)=='e')
	{
		for(int i=0;i<m;i++)
		  {
		  	if(i!=(m-1)/2)
		  	  {
				a[(int)p[i]-65]=100;
				
			 }
		  }
	}
	else 
	{
	for(int i=0;i<m;i++)
		  {
		  	if(i!=(m-1)/2&&a[(int)p[i]-65]!=100)
		  	  a[(int)p[i]-65]=99;
		  }	
		  for(int j=0;j<12;j++)
		  if(a[j]!=99)
		  a[j]=100; 
	}
	//for(int i=0;i<12;i++)
	//cout<<a[i]<<' ';
	//cout<<endl;
	return m;
}
int main()
{
	int a[12],total=12;
	int N;
	
	cin>>N;
	cin.get();
	cin.get();
	while(N--)
	{
		int flag;
		int location;
		for(int i=0;i<12;i++)
	      a[i]=1;
	    char p1[19],p2[19],p3[19];
	    cin.getline(p1,18);
	    cin.getline(p2,18);
	    cin.getline(p3,18);
	    location=pd(p1,a);
	    pd(p2,a);
	    pd(p3,a);
	    int memory;
	    for(int i=0;i<12;i++)
	      if(a[i]!=100)
	        memory=i;
	    char target=(char)(65+memory);
	    if(*(p1+location+1)!='e')
	    {
	    	if(*(p1+location+1)=='u')
			  for(int i=0;i<location;i++)
			     if(p1[i]==target)
				 {
				 	if(i<(location-1)/2)
				 	   {flag=1;break;}
				 	else
				 	   {
						flag=0;break;}
				  } 
			else
			  for(int i=0;i<location;i++)
			     if(p1[i]==target)
				 {
				 	if(i<(location-1)/2)
				 	   {
						flag=0;break;
					}
				 	else
				 	   {flag=1;break;}
				  } 
		} 
		if(*(p2+location+1)!='e')
	    {
	    	if(*(p2+location+1)=='u')
			  for(int i=0;i<location;i++)
			     if(p2[i]==target)
				 {
				 	if(i<(location-1)/2)
				 	   {flag=1;break;}
				 	else
				 	   {flag=0;break;}
				  } 
			else
			  for(int i=0;i<location;i++)
			     if(p2[i]==target)
				 {
				 	if(i<(location-1)/2)
				 	   {
						flag=0;break;}
				 	else
				 	   {
						flag=1;break;}
				  } 
		} 
		if(*(p3+location+1)!='e')
	    {
	    	if(*(p3+location+1)=='u')
			  for(int i=0;i<location;i++)
			     if(p3[i]==target)
				 {
				 	if(i<(location-1)/2)
				 	   {flag=1;break;}
				 	else
				 	   {flag=0;break;}
				  } 
			else
			  for(int i=0;i<location;i++)
			     if(p3[i]==target)
				 {
				 	if(i<(location-1)/2)
				 	   {
						flag=0;break;}
				 	else
				 	   {
						flag=1;break;}
				  } 
		} 
		cout<<target<<" is the counterfeit coin and it is";
		if(flag)
		cout<<" heavy. ";
		else
		cout<<" light. ";
	
	    
	}
	return 0;
	
	
	
 } 
