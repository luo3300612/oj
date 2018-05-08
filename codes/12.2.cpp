#include<cstring>
#include<iostream>
using namespace std;
class String
{
private:
	char *content;
public:
	String()
	{content=NULL;}
	String(char *s)
	{
		content=new char[strlen(s)+1];
		strcpy(content,s);
	}
	String(const String &A)
	{
		content=new char[strlen(A.content)+1];
		strcpy(content,A.content);
	}
	friend istream &operator>>(istream &is,String &s)
	{
		char p[20];
		is>>p;
		s.content=new char[strlen(p)+1];
		strcpy(s.content,p);
		return is;
	}
	friend ostream &operator<<(ostream &os,const String &s)
	{
		os<<s.content<<endl;
	}
	String &operator=(const String &s)
	{
		delete []content;
		content=new char[strlen(s.content)+1];
		strcpy(content,s.content);
		return *this;
	}
	String operator+(const String &s)
	{
		String C;
		C.content=new char[strlen(content)+strlen(s.content)+1];
		strcpy(C.content,content);
		strcpy(C.content+strlen(content),s.content);
		return C;
	}
	friend String operator+(char *p,const String &s)
	{
		String C;
		C.content=new char[strlen(p)+strlen(s.content)+1];
		strcpy(C.content,p);
		strcpy(C.content+strlen(p),s.content);
		return C;
	}
	bool operator==(const String &s)
	{
		if(strcmp(content,s.content)==0)
			return true;
		else
			return false;
	}
	void Stringlow()
	{
		strlwr(content);
	}
	void Stringup()
	{
		strupr(content);
	}
	int has(const char s)const
	{
		int m=0;
		for(int i=0;i<strlen(content);i++)
			if(*(content+i)==s)
				m++;
		return m;
	}
	~String()
	{
		delete []content;
	}
};
int main()
{
	String s1(" and I am a C++ student.");
	String s2="Please enter your name: ";
	String s3;
	cout<<s2;
	cin>>s3;
	s2="My name is"+s3;
	cout<<s2<<".\n";
	s2=s2+s1;
	s2.Stringup();
	cout<<"The string\n"<<s2<<"\ncontains "<<s2.has('A')<<" 'A' characters in it.\n";
	s1="red";
	String rgb[3]={String(s1),String("green"),String("blue")};
	cout<<"Enter the name of a primary color for mixing light :";
	String ans;
	bool success=false;
	while(cin>>ans)
	{
		ans.Stringlow();
		for(int i=0;i<3;i++)
		{
			if(ans==rgb[i])
			{
				cout<<"That's right!\n";
				success=true;
				break;
			}
		}
			if(success)
		break;
	else
		cout<<"Try gain!\n";
	}
	cout<<"Bye\n";
	return 0;

}
