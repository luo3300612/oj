#include<iostream>
#include<cstring>
using namespace std;
bool pd(int *b,int j)
{
	for(int i=j-1;i>=0;i--)
	if(b[i]!=0)
	return 0;
	return 1;
}
void jisuan(int A,int *B,int *c,int SOC)
{
	int weishu=sizeof(B)/sizeof(B[0])*3+5;
	int N=(weishu-1)/9+1;
	for(int i=0;i<SOC;i++)
	  if(i==0)
	  c[i]=B[i]*A;
	  else
	  c[i]=B[i]*A+c[i-1]/1000;
	  for(int i=1;i<SOC-1;i++)
	  c[i]=c[i]%1000;
	  c[0]=c[0]%1000;
}
void zhuanhua(int *a,int *b,int sizeofB,int sizeofA)
{
	int m=0;
    for(int i=0;i<sizeofB;i++)
    {
    	m++;
    	if(i!=sizeofA-1)
	       b[i]=a[i];
	    else
	       break;
    }
    m--;
	b[m]=a[m]%1000;
	if(m<sizeofB-1)
	{
	    b[m+1]=a[m]/1000%1000;
    }
	if(m<sizeofB-2)
	b[m+2]=a[m]/1000000;
}
int cifang(int i)
{
	int sum=1;
	for(int N=0;N<i;N++)
	sum=sum*10;
	return sum;
}
int Weishu(int a)
{
	int m=0,b=a;
	for(;b!=0;m++)
	  b=b/10;
	return m;
 } 
 bool pd2(char *s,int i)
 {
 	for(int j=i+1;j<6;j++)
 	if((int)s[j]!=48)
 	return 0;
 	return 1;
 	
 }
int main()
{
	char s[7];
	int time;
	while(cin>>s>>time)
	{
	
	if(time==1)
	 {
	 	int flg=0;
	 	for(int i=0;i<6;i++)
	 	{
	 	if(s[i]=='.')
	 	flg=1;
	 	if((int)s[i]==48&&flg&&pd2(s,i))
	 	break;
	 	cout<<s[i];
	    }
	    continue;
	 }
	 else
	 {
	 
	    int positionofP;
	    int totalsmallN;
		int number=0;
		for(int i=0;i<6;i++)
		if(s[i]=='.')
		{strcpy(s+i,s+i+1);positionofP=5-i;break;}
		totalsmallN=positionofP*time;
		for(int i=0;i<5;i++)
		number+=((int)s[i]-48)*cifang(4-i);
		if(number/10000==0)
		{number*=10;totalsmallN+=time;}
		int *b,*c;
		b=new int[2]; 
		b[0]=number%1000;
		b[1]=number/1000;
		int sizeofB=2;
		for(int i=1;i<time;i++)
		{
			int W=0;
			for(int j=0;j<3;j++)
			if(b[sizeofB-1]/cifang(j)!=0)
			W++;
			else break;
			int weishu=(sizeofB-1)*3+Weishu(number)-1+W;
			int SOC;
			if(weishu<=7)
			SOC=1;
			else
			SOC=(weishu-2)/3;
	        c=new int[SOC];
			jisuan(number,b,c,SOC);
			delete []b;
			int weishu1;
			if(SOC==1)
			weishu1=Weishu(c[0]);
			else if(SOC==2)
			weishu1=3+Weishu(c[1]);
			else
			weishu1=3*(SOC-1)+Weishu(c[SOC-1]);
			sizeofB=(weishu1-1)/3+1;
            b=new int[sizeofB];
			zhuanhua(c,b,sizeofB,SOC);
			int k=totalsmallN/3;
			int flag=1,flag1=1;
			if(i==time-1)
			{
			
			if(k<=sizeofB)
			{
				if(totalsmallN%3==0)
			       
			    for(int j=sizeofB-1;j>=0;j--)
			    {
			    if(j+1==k)
			    {
				cout<<'.';flag=0;
			    }
			    if(b[j]==0&&flag==0&&pd(b,j))
			    break;
			    else if(b[j]%100==0&&pd(b,j))
			     	{
					 cout<<b[j]/100;break;
				   }
			     	else if(b[j]%10==0&&pd(b,j))
			     	{
			     	 cout.setf(ios::right);    //
                     cout.fill('0');           //网上找的 
                     cout.width(2);  
					 cout<<b[j]/10;
					 break;
				    }
			    
			    if(j!=sizeofB-1)
			    {
			     cout.setf(ios::right);    //
                 cout.fill('0');           //网上找的 
                 cout.width(3);  
		        }
			     cout<<b[j];
		        }
		        else if(totalsmallN%3==1)
		        for(int j=sizeofB-1;j>=0;j--)
			    {
			    if(j+1==k)
			    {
			    	cout.setf(ios::right);    //
                 cout.fill('0');           //网上找的 
                 cout.width(2);  
				cout<<b[j]/10<<'.';flag=0;
				if(b[j]%10==0&&pd(b,j))
				 break;
				 else
				 {cout<<b[j]%10;
				 continue;
			     }
			    }
			    
				
				if(b[j]==0&&flag==0&&pd(b,j))
			    break;
			    else if(b[j]%100==0&&pd(b,j))
			     	{
					 cout<<b[j]/100;break;
				   }
			     	else if(b[j]%10==0&&pd(b,j))
			     	{
			     	 cout.setf(ios::right);    //
                     cout.fill('0');           //网上找的 
                     cout.width(2);  
					 cout<<b[j]/10;
					 break;
				    }
			    
			    if(j!=sizeofB-1)
			    {
			     cout.setf(ios::right);    //
                 cout.fill('0');           //网上找的 
                 cout.width(3);  
		        }
			     cout<<b[j];
		        }
		        else
		        for(int j=sizeofB-1;j>=0;j--)
			    {
			    if(j+1==k)
			    {
				cout<<b[j]/100<<'.';flag=0;
				if(b[j]%100==0&&pd(b,j))
				 break;
				 else if(b[j]%10==0&&pd(b,j))
				 {
				 	cout<<b[j]/10%10;
				 	break;
				 }
				 else
				 {
				 	cout.setf(ios::right);    //
                 cout.fill('0');           //网上找的 
                 cout.width(2);
				 cout<<b[j]%100;
				 continue;  
				 }
			    }
			    
				if(b[j]==0&&flag==0&&pd(b,j))
			    break;
			    else if(b[j]%100==0&&pd(b,j))
			     	{
					 cout<<b[j]/100;break;
				   }
			     	else if(b[j]%10==0&&pd(b,j))
			     	{
			     	 cout.setf(ios::right);    //
                     cout.fill('0');           //网上找的 
                     cout.width(2);  
					 cout<<b[j]/10;
					 break;
				    }
			    
			    if(j!=sizeofB-1)
			    {
			     cout.setf(ios::right);    //
                 cout.fill('0');           //网上找的 
                 cout.width(3);  
		        }
			     cout<<b[j];
		        }
		        
		    }
		    else
		    {
		    	cout<<'.';
		    	int No0=totalsmallN-sizeofB*3;
		    	for(int i=0;i<No0;i++)
		    	cout<<0;
		    	for(int i=sizeofB-1;i>=0;i--)
		    	{
		    	 if(b[i]==0&&pd(b,i))
			     break;
			     
			    else if(b[i]%100==0&&pd(b,i))
			     	{
					 cout<<b[i]/100;break;
				   }
			     	else if(b[i]%10==0&&pd(b,i))
			     	{
			     	 cout.setf(ios::right);    //
                     cout.fill('0');           //网上找的 
                     cout.width(2);  
					 cout<<b[i]/10;
					 break;
				    }
		
				 
		    	 cout.setf(ios::right);    //
                 cout.fill('0');           //网上找的 
                 cout.width(3);  
                 cout<<b[i];
				}
			}
		}
		    
			if(i!=time-1)
			{
			delete []c;
		    }
		}
	}
	}
	  
	return 0; 
} 
