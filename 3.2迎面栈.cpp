#include<iostream>
using namespace std;
const int MAX=200;
struct a
{
	int stack[MAX];
	int top1;
	int top2;
};
void initStack(a *s)
{
	s->top1=-1;
	s->top2=-1;
}
void clearStack(a *s)
{
	s->top1=-1;
	s->top2=MAX;
}
int getTop1(a *s)
{
	if(s->top1==-1)
	{
		cout<<"empty"<<endl;
	}
	return s->stack[s->top1];
 } 
int getTop2(a *s)
{
	if(s->top2==MAX)
	{
		cout<<"empty"<<endl;
	}
	return s->stack[s->top2];
 } 
void push1(a *s,int b)
{
	if(s->top2-s->top1==1)
	{
		cout<<"overflow"<<endl;
	}
	s->top1++;
	s->stack[s->top1]=b;
}
void push2(a *s,int b)
{
	if(s->top2-s->top1==1)
	{
		cout<<"overflow"<<endl;
	}
	s->top2--;
	s->stack[s->top2]=b;
}
int pop1(a *s)
{
	if(s->top1==-1)
	{
		cout<<"empty\n";
	}
	s->top1--;
	return s->stack[s->top1+1];
}
int pop2(a *s)
{
	if(s->top2==MAX)
	{
		cout<<"empty\n";
	}
	s->top2++;
	return s->stack[s->top2-1];
}
