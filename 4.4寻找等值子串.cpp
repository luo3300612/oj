#include<iostream>
#include<cstring>
using namespace std;
void findS(int *s,int n)
{
	int MAX=0;
	int record;
	int num=0;
	for(int i=0;i<n-1;i=i+num+1)    //·ÀÖ¹ÖØ¸´±È½Ï 
	{
		num=0;
		int j=i+1;
		while(j<n&&s[i]==s[j])
		{
			num++;
			j++;
		}
		if(num>MAX)
		{
		    MAX=num;
	    }
	}
	if(MAX==0)
	cout<<"no!"<<endl;
	else
	cout<<MAX;
	cout<<endl;
}
int main()
{
	int s[25]={1,2,3,4,5,6,7,8,9,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2};
	findS(s,25);
	return 0;
}
