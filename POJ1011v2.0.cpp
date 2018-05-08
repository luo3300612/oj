#include<iostream>
#include<algorithm>
using namespace std;
bool pd(int *a,int sizeofa,int target)
{
	int sum=0;
	int f=0;
	int t=sizeofa;
	int flag=1;
     for(int i=0;i<t;)
	 {
	 	while(sum!=target)
	 	{
	 		if(flag==1)
	 		{
	 			sum+=a[i];
	 			flag=2;
			 }
			 else if(flag==2)
			 {
			 	sum=sum+a[t-1]-a[i];
			 	flag=3;
			 }
			 else
			 {
			 	sum=sum+a[i];
			 	flag=1;
			 	i++;
			 	t--;
			 }
			 if(sum>target&&flag==2)
			 {
			 return 0;
		     }
		 }
		 if(sum==target)
		 {
		 	sum=0;
		 	f=0;
		 	if(flag==2)
		 	{
		 		flag=1;
		 		i++;
		 		continue;

			 }
		 	else if(flag==3)
		 	{
		 		flag=1;
		 		t--;
		 		continue;
		 	}
		 	else
		 	{
		 		flag=1;
		 		i++;
		 		t--;
		 		continue;
			 }
		 }
	 }	
	 return 1;
}

int main()
{
	int N;
	cin>>N;
	while(N)
	{
		int *a;
		a=new int[N];
		int sum=0;
		for(int i=0;i<N;i++)
		{
			cin>>a[i];
		sum=sum+a[i];
	    }
	    sort(a,a+N);
	    int flag=1;
	    for(int i=1;i<N;i++)
	    if(a[0]!=a[i])
	    flag=0;
        int average;
        if(flag==1)
        cout<<a[0]<<endl; 
        if(!flag)
		for(int i=sum-1;i>=1;i--)
		{
			if(i==1)
			{cout<<sum<<endl;flag=0;break;}
			if(sum%i==0)
			{
				average=sum/i;
				if(pd(a,N,average))
				{
				cout<<average<<endl;
				flag=0;
				break;
			    }
			    else
			    continue;
			}
		}
		cin>>N;
		delete []a;
	}
}
