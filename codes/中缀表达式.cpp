#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
bool order(char ch,char ch2)
{
	if((ch=='+'||ch=='-'||ch==')'||ch2=='*'||ch2=='/'||ch=='#')&&ch2!='('&&ch!='(')
	return true;
	else 
	return false;
}
int calculate(int a,int b,char ch)
{
	cout<<"a="<<a<<"  b="<<b<<endl;
	cout<<"ch=="<<ch<<endl;
	if(ch=='+')
	return a+b;
	else if(ch=='-')
	return a-b;
	else if(ch=='*')
	return a*b;
	else if(ch=='/')
	return a/b;
}
int main()
{
	stack<int> OPND;
	stack<char> OPRT;
	OPRT.push('#'); 
	char str[100];
	cin>>str;
    str[strlen(str)]='#';
    str[strlen(str)+1]='\0';
	int c=0;
	int flag=0;
	for(int i=0;;i++)
	{
		if(str[i]>=48&&str[i]<=57)
		{
		c=c*10+str[i]-48;
		cout<<c<<endl;
		flag=1;
	    }
	    else
	    {
	    	if(flag)
	    	{
	    		OPND.push(c);
	    		c=0;
	    		flag=0;
			}
			if(str[i]=='#'&&OPRT.top()=='#')
			{cout<<OPND.top();break;}
			else if(str[i]==')'&&OPRT.top()=='(')
			OPRT.pop();
			else if(!order(str[i],OPRT.top())||OPRT.top()=='#')
			OPRT.push(str[i]);
			else
			{
				int a=OPND.top();
				OPND.pop();
				int b=OPND.top();
				int R=calculate(b,a,OPRT.top());
				OPND.pop();
				OPRT.pop();
				OPND.push(R);
				i--;
			}
		}
		
	}
	return 0;
 } 
