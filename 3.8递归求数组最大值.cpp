#include<iostream>
using namespace std;
int MAX=0;
void compare(int *a,int start,int mid)
{
	if(a[start]<a[mid+1])
	a[start]=a[mid+1];
}
void DAC(int *a,int start,int end) 
{
	if(start<end)
	{
		int q=(start+end)/2;
		DAC(a,start,q);
		DAC(a,q+1,end);
		compare(a,start,q);
	}
}
int main()
{
	int a[]={2,3,5,4,1,2,610,4,8,6,2,888};
	DAC(a,0,11);
	cout<<a[0]<<endl;
}
