#include<iostream>
using namespace std;
void merge(int *A,int p,int q,int r)
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
	
	
	 int i=1,j=1;
	 for(int k=p;k<=r;k++)
	 if((L[i]<=R[j]||j==n2+1)&&(i!=n1+1))
	 {
	     A[k]=L[i];
		 i=i+1;	
	 }	
	 else
	 {
	 	A[k]=R[j];
	 	j=j+1;
	 }
} 
void mergeSort(int *a,int start,int end)
{
	if(start<end)
	{
		int mid=(end+start)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
int search(int v,int *a,int start,int end)
{
	if(start>=end&&a[start]!=v)
	return 999999;
	int mid=(start+end)/2;
	if(v==a[mid])
	return mid;
	else
	{
		if(v<a[mid])
		return search(v,a,start,mid);
		else
		return search(v,a,mid,end);
	}
}
int main()
{
	int A[]={2,5,6,4,11,1,14,16,3,12,1,25,73};
	mergeSort(A,0,12);
	for(int i=0;i<13;i++)
	cout<<A[i]<<' ';
	cout<<endl;
	cout<<search(25,A,0,12);
}
