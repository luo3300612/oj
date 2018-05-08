#include<iostream>
#include<stdlib.h> 
#include<algorithm>
using namespace std;
typedef int DataType;
struct BTNode{
	BTNode *LChild;
	DataType data;
	BTNode *RChild;
};
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
BTNode* createBTree()
{
	BTNode *bt=NULL;
	int elem;
	cin>>elem;
	if(elem!=-1)
	{
		bt=new BTNode;
		if(bt==NULL)
		{
			cout<<"内存分配错误"<<endl;
			exit(1);
		}
		bt->data=elem;
		bt->LChild=createBTree();
		bt->RChild=createBTree();
	}
	return bt;
 } 
 void midOrder(BTNode *root)
 {
 	if(NULL!=root)
 	{
 		midOrder(root->LChild);
 		midOrder(root->RChild);
 		cout<<root->data;
	 }
 }
 BTNode* searchBTree(BTNode *root,DataType elem)   //先序查找 
 {
 	BTNode *t;
 	if(NULL==root)
 	return NULL;
 	if(root->data==elem)
 	return root;
 	else
 	{
 		t=searchBTree(root->LChild,elem);
 		if(NULL!=t)
 		return t;
 		else
 		return searchBTree(root->RChild,elem);
	 }
 }
 int getDepth(BTNode *root)
 {
 	int LDep,RDep;
 	if(NULL==root)
	 {
	 	return 0;
	  } 
	  else
	  {
	  	LDep=getDepth(root->LChild);
	  	RDep=getDepth(root->RChild);
	  	return (LDep>RDep)?LDep+1:RDep+1;
	  }
 }
 void preOrder(BTNode *root)
 {
 	if(NULL!=root)
 	{
 		cout<<root->data;
 		preOrder(root->LChild);
 		preOrder(root->RChild);
	 }
  } 
  BTNode *HufTree(int *a,int N)
 {
     qsort(a,n,sizeof(a[0]),cmp);
	 if(n==1)
	 return NULL;
	 BTNode *p1,*p2,*p3;
	 p1=new BTNode;
	 p2=new BTNode;
	 p1->data=a[n-1];
	 p2->data=a[n-2];
	 a[n-2]=a[n-1]+a[n-2];
	 n--;
	 p3->LChild=p1;
	 p3->RChild=p2;	
 }
 int main()
 {
 	int a[10]={2,5,4,2,3,6,2,1,3,5};
 	qsort(a,10,sizeof(a[0]),cmp);
 	for(int i=0;i<10;i++)
 	cout<<a[i]<<' ';
 }
