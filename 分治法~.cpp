#include<iostream>
using namespace std;
int N=12;
 void show(int *a,int N)
 {
 	for(int i=1;i<=N;i++)
 	{
 		cout<<a[i]<<' ';
	 }
 }
void MERGE(int *A,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int *L,*R;
	L=new int[n1+1];
	R=new int[n2+1]; 
	for(int i=1;i<=n1;i++)
	L[i]=A[p+i-1];
	
	for(int j=1;j<=n2;j++)
	R[j]=A[q+j];
	cout<<"L:"<<endl;
	show(L,n1);
	cout<<endl;
	cout<<"R:"<<endl;
	show(R,n2);
	cout<<endl;
	cout<<"A:"<<endl;
	show(A,N);
	cout<<endl;
	int i=1,j=1;
	for(int k=p;k<=r;k++)
	if(L[i]<=R[j]||j==n2+1)
	{
		A[k]=L[i];
		i=i+1;
		//if(i==n1+1)
		//{
			//cout<<"i=n1+1"<<endl;
		//	for(int m=1;m<=n2-j+1;m++)
		//	{
		//		A[k+m]=R[j+m-1];
		//	}
		//	break;
		//}
    }
    else if(L[i]>R[j]||i==n1+1)
    {
    	A[k]=R[j];
    	j=j+1;
    	//if(j==n2+1)
		//{
			//cout<<"j=n2+1"<<endl;
		//	for(int m=1;m<=n1-i+1;m++)
		///	{
		//		A[k+m]=R[i+m-1];
		//	}
		//	break;
		//}
	}
}

 
 void MERGESORT(int *A,int p,int r)
 {
 	if(p<r)
 	{    
 		int q=(p+r)/2;
 		MERGESORT(A,p,q);
 		MERGESORT(A,q+1,r);
 		MERGE(A,p,q,r);
	 }          
 }

 int main()
 {
 	int A[]={2,3,5,4,8,6,9,2,5,6,3,1,2};
 	MERGESORT(A,1,12);
 	show(A,12);
 	
 }
