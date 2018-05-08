#include<iostream>
using namespace std;
enum NodeType{head,atom,sub};
typedef char DataType;
struct GNode
{
	NodeType type;
	union datsub;
	{
		DataType data;
		struct GNode *sub;
	}
	GNode *next;
};
GNode *initGlist()
{
	GNode *head;
	head=new GNode;
	head->type=0;
	head->datsub.sub=NULL;
	head->next=NULL;
	return head;
}
int getlength(GNode *head)
{
	int len=0;
	GNode* p=head;
	if(p->type==0)
	p=p->datsub.sub;
	if(NULL!=p)
	{
		len=getLength(p->next);
		return len+1;
	}
	else
	return 0;
}
int getDepth(GNode *head)
{
	int depth=0,maxDepth=0;
	GNode *p=head;
	if(p->type==0)
	p=p->datsub.sub;
	while(NULL!=p)
	{
		if(p->type==2)
		{
			depth=getDepth(p->datsub.sub);
			if(depth>maxDepth)
			maxDepth=depth;
		}
		p=p->next;
	}
	return maxDepth+1;
}
void outputGlist(GNode *head)
{
	if(head->type==0||head->type==2)
	{
		cout<<'('
		if(head->datsub.sub==NULL)
		cout<<' ';
		else
		outputGList(head->datsub.sub); 
	}
	else
	cout<<head->datsub.data;
	if(head->type==0||head->type==2)
	cout<<')';
	if(head->next!=NULL)
	{
		cout<<","<<endl;
		outputGLList(head->next);
	}
}

