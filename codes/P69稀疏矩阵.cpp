#include<iostream>
using namespace std;
const int M=6;
const int N=6;
const int MaxSize=200;
typedef int DataType;
struct TripleElem{
	int i,j;
	DataType v;
};
struct Matrix{
	TripleElem matData[MaxSize];
	int p[M+1],t[M+1];
	int m,n,k;
};
void input(Matrix &pMat,int n)
{
	pMat.m=n;
	int a;
	int count=0; 
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		cin>>a;
		if(a)
		{
			pMat.matData[count].i=i+1;
			pMat.matData[count].j=j+1;
			pMat.matData[count].v=a;
			count++; 
		}
		
	}
	pMat.k=count;
}
void initMark(Matrix &pMat)
{
	int i,j;
	for(i=1;i<=pMat.m;i++)
	pMat.t[i]=0;                             //�Ƚ�ÿ�з���Ԫ�صĸ�����Ϊ0������֮�����++���� 
	for(j=0;j<pMat.k;j++)                     
	pMat.t[pMat.matData[j].i]++;              //k�Ƿ���Ԫ���ܸ�����pMat.matData[j].i��ʾ��j��Ԫ�����������������i�д���Ԫ����t[i]++ 
	pMat.p[1]=0;
	for(i=2;i<=pMat.m;i++)
	pMat.p[i]=pMat.p[i-1]+pMat.t[i-1];            //��i�е�һ��Ԫ������Ԫ���е�����Ӧ���ǵ�i-1�е�һ��Ԫ�ص��±���ϵ�i-1��Ԫ�صĸ��� 
}
void output(Matrix &pMat)
{
	for(int i=0;i<pMat.k;i++)
	cout<<i<<"  "<<"("<<pMat.matData[i].i<<","<<pMat.matData[i].j<<"):"<<pMat.matData[i].v<<endl;
}
int main()
{
	int w;
	cin>>w;
	Matrix a;
	input(a,w);
	initMark(a);
	cout<<'p'<<' '<<'t'<<endl;
	for(int i=1;i<=w;i++)
	{
		cout<<a.p[i]<<' '<<a.t[i]<<endl;
	}
	output(a);
	
}
