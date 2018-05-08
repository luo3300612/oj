#include<iostream>
using namespace std;
void MERGE(int *a,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int *l1,*l2;
	l1=new int[n1+1];
	l2=new int[n2+1];
	for(int i=1;i<=n1;i++)
	l1[i]=a[p+i-1];
	for(int j=1;j<=n2;j++)
	l2[j]=a[q+j];
	int m=1,n=1;
	for(int k=p;k<=r;k++)
	if(l1[m]<=l2[n]||n==n2+1)
	{a[k]=l1[m];m++;}
	else if(l1[m]>l2[n]||m==n1+1)
	{a[k]=l2[n];n++;}
	
 } 
void MERGESORT(int *a,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		MERGESORT(a,p,q);
		MERGESORT(a,q+1,r);
		MERGE(a,p,q,r);
	}
}
int main()
{
	int a[]={2,5,6,4,8,6,2,1,3,2,5,4,8,9,6,1,2,3};
	MERGESORT(a,1,17);
	for(int i=1;i<=17;i++)
	cout<<a[i]<<' ';
}
