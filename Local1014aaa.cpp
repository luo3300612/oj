#include<iostream>
using namespace std;
char a[6][6];
char b[6][6];
int count=0;
int max=0;
void trans(int row,int col,int N)
{
     for(int i=row-1;i>=0;i--)
        if(b[i][col]!='X'&&b[i][col]!='A')
			b[i][col]='O';
		else if(b[i][col]=='X')
			break;
	for(int j=row+1;j<N;j++)
		if(b[j][col]!='X'&&b[j][col]!='A')
			b[j][col]='O';
		else if(b[j][col]=='X')
			break;
	for(int k=col-1;k>=0;k--)
		if(b[row][k]!='X'&&b[row][k]!='A')
			b[row][k]='O';
		else if(b[row][k]=='X')
			break;
	for(int l=col+1;l<N;l++)
		if(b[row][l]!='X'&&b[row][l]!='A')
			b[row][l]='O';
		else if(b[row][l]=='X')
			break;
}
int showAc(int N)
{
	int count=0;
	for(int i=0;i<N;i++)
	{for(int j=0;j<N;j++)
		{
		     //cout<<a[i][j]<<' ';
			 if(a[i][j]=='A')
				 count++;
		}
	    //cout<<endl;
	}
	//cout<<endl;
	return count;
}
bool cover(int row,int N)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			b[i][j]=a[i][j];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(b[i][j]=='A')
				trans(i,j,N);
	for(int j=0;j<N;j++)
		if(b[row][j]=='.')
			return false;
	return true;
}
bool panduan(int row,int col,int N,int ch)
{
	if(ch=='A'||ch=='X')
		return false;
	for(int i=row-1;i>=0;i--)
        if(a[i][col]=='A')
			return false;
		else if(a[i][col]=='X')
			break;
	for(int j=row+1;j<N;j++)
		if(a[j][col]=='A')
			return false;
		else if(a[j][col]=='X')
			break;
	for(int k=col-1;k>=0;k--)
		if(a[row][k]=='A')
			return false;
		else if(a[row][k]=='X')
			break;
	for(int l=col+1;l<N;l++)
		if(a[row][l]=='A')
			return false;
		else if(a[row][l]=='X')
			break;
	return true;
}
void solve(int row,int N)
{
	for(int j=0;j<N;j++)
	{
		char ch=a[row][j];
		a[row][j]='A';
		if(panduan(row,j,N,ch))
		{
			if(cover(row,N))
			{
				if(row==N-1)
				{
					int t=showAc(N);
					if(t>::max)
						::max=t;
				}
				else
				{
					solve(row+1,N);
				}

			}
			else
				solve(row,N);
		}
		else
		{;}//cout<<row<<","<<j<<" can not!"<<endl;}
		a[row][j]=ch;
	}
}
int main()
{
	int N;
	
	while(cin>>N)
	{
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>a[i][j];
	
	solve(0,N);//从第一行开始会导致情况不全
	cout<<::max<<endl;
    }
	return 0;
}
