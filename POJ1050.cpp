#include<iostream>
using namespace std;
int MAX; 
struct sanyuanzu
{
	int x;
	int y;
	int num;
};
int sum(int i,int j,int n,int co,sanyuanzu *k,int *t)
{
	int start=0;
	for(int m=0;m<i;m++)
	start+=t[m];
	//cout<<start<<endl;
	int sum=0;
	
	while(k[start].x<=i+n-1)
	{
	int ST=start;
	//cout<<"ST="<<ST<<endl; 
	while(k[ST].y!=j)
	ST++;
	while(k[ST].y<=j+co-1&&k[ST].x==start)
	{
		//cout<<"+k["<<ST<<"]="<<k[ST].num<<" ";
		sum+=k[ST].num;
	    //cout<<sum<<endl;
		if(k[ST].y==j+co-1)
		break;
		ST++;
	}
	//cout<<"t[0]="<<t[0]<<endl;
	//cout<<"kstart.x="<<k[start].x<<endl;
	start=start+t[k[start].x];
	//cout<<"start="<<start<<endl;
    }
    //cout<<"end"<<endl;
    return sum;
}
int main()
{
	int N;
	while(cin>>N)
	{
		 int a;
	     sanyuanzu *arr;
		 arr=new sanyuanzu[N*N];
		 int *p,*t;
		 p=new int[N];
		 t=new int[N];
		 int count=0;
		 for(int i=0;i<N;i++)
		 {
		 t[i]=0;
		 int flag=0;
		 for(int j=0;j<N;j++)
		 {
		 	cin>>a;
		 	if(!flag&&a)
		 	 {
		 		p[i]=j;
		 		flag=1;
		 		arr[count].num=a;
		 		arr[count].x=i;
		 		arr[count].y=j;
		 		count++;
		 		t[i]++;
		 		continue;
			  }
			 if(a)
			  {
			    arr[count].num=a;
		 		arr[count].x=i;
		 		arr[count].y=j;
		 		count++;
		 		t[i]++;	
			  }
		   }
		 }
		 MAX=arr[0].num;
		 //cout<<MAX<<endl;
		 for(int i=1;i<=N;i++)
		 for(int j=1;j<=N;j++)
		 	for(int row=0;row<N+1-i;row++)
		 	for(int col=0;col<N+1-j;col++)
		 	{
		 		int w=sum(row,col,i,j,arr,t);
		 		cout<<w<<endl;
		 		if(w>MAX)
		 		{
		 		//	cout<<"row="<<row<<" col="<<col<<" size="<<i<<"*"<<j<<" and MAX="<<w<<endl;
				 MAX=w;
			    }
			 }
		 
		 cout<<MAX<<endl;
		 
	}
}
