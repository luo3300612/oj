#ifndef STRING_H_
#define STRING_H_
#include<string.h>
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
		return & is;
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
#endif