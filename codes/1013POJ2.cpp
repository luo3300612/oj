#include<iostream>
#include<string.h>
using namespace std;
void show(bool *M)
{
	for(int i=0;i<=10;i++)
	cout<<M[i]<<' ';
}
int main()
{
	int n;
	cin>>n;
	char s;
	cin.get(s);
	while(s!='\n')
	{
		cin.get(s);
	}
	while(n--)
	{
	
	
	char s[3][20];
	cin.getline(s[0],20);
	cin.getline(s[1],20);
	cin.getline(s[2],20);
    char s0[3][5];
	for(int j=0;j<=2;j++)
	{
	bool flag=0;
	for(int i=0;i<17;i++)
	{
		if(s[j][i]==' '&&flag==1)
		{
			//cout<<s[j]+(i+1)<<endl;
			
			strcpy(s0[j],s[j]+(i+1));
			for(int t=0;s0[j][t]!='\0';t++)
			{
				if(s0[j][t]==' ')
				{
				s0[j][t]='\0';
				break;
			    }
			}
			s[j][i]='\0';
			break;
		}
		else if(s[j][i]==' '&&flag==0)
		flag=1;
	}
    }
    
	int M[12]={1,1,1,1,1,1,1,1,1,1,1,1};
	for(int i=0;i<3;i++)
	{
		if(!strcmp(s0[i],"even"))
		{
			for(int j=0;s[i][j]!='\0';j++)
			{
				if(s[i][j]!=' ')
				{
				M[(int)s[i][j]-65]-=10;
			    }
			}
		}
		else
		{
			for(int j=0;s[i][j]!='\0';j++)
			{
				if(s[i][j]!=' ')
				{
				M[(int)s[i][j]-65]+=1;
			    }
			}
		}
	}
	//show(M);
	int index=-100,num=-100;
	for(int i=0;i<12;i++)
	{
		if(M[i]>index)
		{
		num=i;
		index=M[i];

	    }
	}
	
	for(int i=0;i<3;i++)
	{
		int mid=0;
		if(!strcmp(s0[i],"up"))
		{
			for(int j=0;s[i][j]!='\0';j++)
			{
				if(s[i][j]==' ')
				{
					mid=j;
					break;
				}
			}
			for(int j=0;s[i][j]!='\0';j++)
			{
				if(s[i][j]==(char)(num+65))
				{
					if(j<mid)
					cout<<(char)(num+65)<<" is the counterfeit coin and it is heavy. ";
					else
					cout<<(char)(num+65)<<" is the counterfeit coin and it is light. ";
					break;
				}
			}
			break;
		}
		else if(!strcmp(s0[i],"down"))
		{
			for(int j=0;s[i][j]!='\0';j++)
			{
				if(s[i][j]==' ')
				{
					mid=j;
					break;
				}
			}
			for(int j=0;s[i][j]!='\0';j++)
			{
				if(s[i][j]==(char)(num+65))
				{
					if(j<mid)
					cout<<(char)(num+65)<<" is the counterfeit coin and it is light. ";
					else
					cout<<(char)(num+65)<<" is the counterfeit coin and it is heavy. ";
					break;
				}
			}
			break;
		}
	}
}

	return 0;
 } 
