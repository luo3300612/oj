#include<iostream>
using namespace std;
struct lb{
bool t;
lb *next;
};

void create(lb *head,int k)
{
	int time=2*k-1;
	lb *p2=head;
	if(time==1)
	{
		lb *p1;
		p1=new lb;
		p1->t=false;
		p2->next=p1;
		p1->next=p2;
	}
	else
	{
	while(time)
	{
		lb *p1;
		p1=new lb;
		if(time>k)
			p1->t=false;
		else
			p1->t=true;
		//cout<<p1->t<<endl;
		p2->next=p1;
		p2=p1;
		time--;
	}
	p2->next=head;
    }
}
void show(lb *head)
{
	lb *p1,*p2=head;
	//cout<<head->t<<endl;
	int flag=0;
	do
	{
		p1=p2;
		p2=p2->next;
		//cout<<p2->t<<endl;
		if(p2->t!=p1->t)
		flag++;
	}while(flag!=3);
}
void del(lb *head,int k)
{
	lb *p1,*p2=head;
	for(int i=0;i<k;i++)
	{
		p1=p2;
		p2=p2->next;
		delete p1;
	}
 } 
void Del(int k)
{
	if(k==1)
	cout<<2<<endl;
	else
	for(int i=1;;i++)
	{
		int times=0;
		lb *head;
		head=new lb;
		head->t=false;
		create(head,k);
		lb *p1,*p2=head;
		int number=0;
	   
	
		while(number!=k)
		{
			//cout<<endl; 
		//show(p2);
		//cout<<endl;
		
		for(int j=0;j<i;j++)
		{p1=p2;p2=p2->next;times++;}
		if(p2->t==false)
            {
            del(p2,2*k-times);
			break;
		    }
		p1->next=p2->next;
		p2=p2->next;
		
		number++;
		}
		if(number==k)
		{cout<<i+1<<endl;break;}
		else
		continue;

	}

} 
int main()
{
	int N;
	cin>>N;
	while(N)
	{
		
		Del(N);
		cin>>N;
	}
	return 0;
}
