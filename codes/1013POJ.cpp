#include<iostream>
#include<cstring>
using namespace std;
void del(char *s,char ch)
{
	for(int i=0;s[i]!='\0';i++)
	if(s[i]==ch)
	{strcpy(s+i,s+i+1);}
}
int main()
{
	int N;
	cin>>N;
	cin.get();
	while(N--)
	{
		char s[]="ABCDEFGHIJKL";

		char p1[3][7],p2[3][7],p3[3][5];
		cin>>p1[1]>>p2[1]>>p3[1]>>p1[2]>>p2[2]>>p3[2]>>p1[3]>>p2[3]>>p3[3];
		for(int i=0;i<3;i++)
		{
		     if(strcmp(p3[i],"even")==0)
			 {
			 	for(int j=0;p1[j]!='\0';j++)
			 	{
			          del(s,p1[i][j]);
					  del(s,p2[i][j]);		
				 }
			 }	
			 else
			 {
			 	int flag=0;
			 	for(int m=0;s[m]!='\0';m++)
			 	{
			 		for(int j=0;p1[j]!=0;j++)
			 		{
			 			if(s[m]==p1[i][j]||s[m]==p2[i][j])
			 			flag=1;
					 }
					 if(flag==0)
					 {
					 	strcpy(s+m,s+m+1);
					 }
					 flag=0;
				 }
			 }
		}
		cout<<s;	
	}
}
