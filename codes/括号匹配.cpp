#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool pipei(char ch,char top)
{
	if(ch==')'&&top=='(')
	return 1;
	else if(ch==']'&&top=='[')
	return 1;
	else if(ch=='}'&&top=='{')
	return 1;
	return 0;
}
int main()
{
	stack<char> s1;
	char str[100];
	int N;
	cin>>N;
	while(N--)
	{
		cin>>str;
		if(strlen(str)%2)
		cout<<"cannot"<<endl;
		else
		{
			  s1.push('#');
		      for(int i=0;str[i]!='\0';i++)
			  {
			  	cout<<i<<endl;
			  	cout<<11111<<endl;
			  	cout<<str[i]<<endl;
			  	cout<<s1.top();
			  	cout<<"next panduan"<<str[i]<<" he "<<s1.top()<<endl;
			  	if(pipei(str[i],s1.top()))
			  	{
			  	cout<<str[i]<<"and"<<s1.top()<<"   pipei"<<endl;
			  	s1.pop();
			    }
			  	else
			  	{
				cout<<str[i]<<"and"<<s1.top()<<"   bupei"<<endl;  
			  	s1.push(str[i]);
			    }
			  }
			  if(s1.top()=='#')
			  cout<<"yes"<<endl;
			  else
			  cout<<"no"<<endl;			
		}
	}
	
	
	return 0;
}
