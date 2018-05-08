#include<iostream>
using namespace std;
void merge(int *a,int *b,int low,int mid,int high)
{
	int s=low,t=mid+1,k=low;
	while(s<=mid&&t<=mid)
	{
		if(a[s]<a[t])
		{
			b[k]=a[s];
			s++;
		}
		else
		{
			b[k]=a[t];
			t++;
		}
		k++;
	}
	if(s==mid+1)
	{
		for(int i=k;i<=high;i++)
		b[i]=a[t++];
	}
	else
	{
		for(int i=k;i<=high;i++)
		b[i]=a[s++];
	}
	for(int i=low;i<=high;i++)
	a[i]=b[i];
}

void mergeSort(int a[],int b[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergeSort(a,b,low,mid);
		mergeSort(a,b,mid+1,high);
		merge(a,b,low,mid,high);
	}
}
int main()
{
	int a[]={2,5,6,4,5,8,6,2,4,5,6,3,6,6};
	int b[14];
	mergeSort(a,b,0,13);
	for(int i=0;i<14;i++)
	cout<<a[i]<<' ';
	cout<<endl;
	for(int i=0;i<14;i++)
	cout<<b[i]<<' ';
 } 

