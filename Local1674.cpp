#include<iostream>
using namespace std;
int a[101][101];
int pd[101][101];
int M,N;
int count(int i,int j)
{
	if(pd[i][j]!=0)
	return pd[i][j];
	int max=0;
	int D;
    for(int t=0;t<4;t++)
      {
      	int x,y;
          if(t==0)
          {
              x=i-1,y=j;  	
		  }
		  else if(t==1)
		  {
		  	x=i+1,y=j;
		  }
		  else if(t==2)
		  {
		  	x=i,y=j-1;
		  }
		  else
		  {
		  	x=i,y=j+1;
		  }
          if(x>=0&&x<M&&y>=0&&y<N&&a[x][y]<a[i][j])
          {
              D=count(x,y);
              if(D>max)
			  max=D;
          }
           
      }
    pd[i][j]=max+1;
    return max+1;
}
int main()
{
	while(cin>>M>>N)
	{
		int MAX=-1,t;
		for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			pd[i][j]=0;
			cin>>a[i][j];
		 } 
		for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			t=count(i,j);
			if(t>MAX)
			MAX=t;
		}
		cout<<MAX<<endl;
	}
	
}
