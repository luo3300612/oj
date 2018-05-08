#include<iostream>
#include<cstring>
const int MaxSize=200;
using namespace std;
void partStringLen(char *pMode,int *n)
{
	int i=1,j=0;
	int m=strlen(pMode);
	n[0]=0;
	while(i<m)
	{
		if(pMode[i]==pMode[j])
		{
			n[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
          j=n[j-1];
          else
          n[i++]=0;
	}
}
int kmpMatch(char *pDst,char *pMode)
{
	int n=strlen(pDst);
	int m=strlen(pMode);
	int i=0,j=0,nxt[MaxSize];
	partStringLen(pMode,nxt);
	while(i<n)
	{
		if(pDst[i]==pMode[j])
		{
			if(j==m-1)
			return i-j;
			i++;
			j++;
		}
		else
		{
			if(j>0)
			j=nxt[j-1];
			else
			i++;
		}
	}
	return -1;
}
void deS(char *ori,char *target)
{
	int position=kmpMatch(ori,target);
	int m=strlen(target);
	if(position!=-1)
	{
	strcpy(ori+position,ori+position+m);
	deS(ori+position,target);
    }
}
int main()
{
	char s[]="asddfkgjdnasdkgdnfjasdasdkfgdogdglasd";
	char d[]="asd";
	deS(s,d);
	cout<<s<<endl;
}
