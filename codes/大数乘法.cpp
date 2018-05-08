#include<iostream>
#include<cstring> 
using namespace std;
void add(char *s1,char *s2)
{
	int w=0;
	int r;
	int count=0;
	for(int i=0;i<strlen(s1)||i<strlen(s2);i++)
	{
		r=(int)(s1[i]-48)+(int)(s2[i]-48);
		s1[i]=(r+w)%10+48;
		w=(r+w)/10;
		count++;
	}
	if(w!=0)
	s1[count]=w+48;
	
	cout<<s1;
}
void mult(char *s1,char *s2)
{
	char re[100][102];
	int w=0;
	int p1,p2;
	for(int i=strlen(s2)-1,p2=0;i>=0;i--,p2++)
	{
		for(int t=0;t<p2;t++)
		re[p2][t]='0';
		for(int j=strlen(s1)-1,p1=p2;j>=0;j--,p1++)
		{
			int result=(int)(s1[j]-48)*(int)(s2[i]-48);
			re[p2][p1]=(result+w)%10+48;
			w=(result+w)/10;
			//cout<<re[p2][p1];
			if(w!=0&&j==0)
	    	{
			re[p2][p1+1]=w+48;
			cout<<re[p2][p1+1];
			re[p2][p1+2]='\0';
			w=0;
	    	 } 
	     	 else if(w==0&&j==0)
	    	 {
		 	re[p2][p1+1]='\0';
	    	 }
		}
		cout<<re[p2];
		cout<<endl;
	}
	//char RESULT[100001]
	//for(int i=0;i<;i++)
	//{
	//	for(int j=0;j<=i;j++)
	//	{
	//		RESULT[i]=(int)RESULT[i]+(int)re[j][i]
	//	}
	//}
	
 } 
 int main()
 {
 	char s1[]="1090",s2[]="101",s3[]="0000";
 	mult(s1,s2);
 	add(s1,s2);
 	return 0;
 }
