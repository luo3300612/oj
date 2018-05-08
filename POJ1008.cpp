#include<iostream>
#include<cstring>
using namespace std;
class haab
{
	private:
	int NOTD;
	char *NOM;
	int NOTY;
	public:
		haab(int a,char *p,int b)
		{
			NOTD=a;
			NOM=new char[strlen(p)+1];
			strcpy(NOM,p);
			NOTY=b;
		}
		int calculate()
		{
			int S=0;
			if(strcmp(NOM,"pop")==0)
			   S+=0;
			else if(strcmp(NOM,"no")==0)
			   S+=20;
			else if(strcmp(NOM,"zip")==0)
			   S+=40;
			else if(strcmp(NOM,"zotz")==0)
			   S+=60;
			else if(strcmp(NOM,"tzec")==0)
			   S+=80;
			else if(strcmp(NOM,"xul")==0)
			   S+=100;
			else if(strcmp(NOM,"yoxkin")==0)
			   S+=120;
			else if(strcmp(NOM,"mol")==0)
			   S+=140;
			else if(strcmp(NOM,"chen")==0)
			   S+=160;
			else if(strcmp(NOM,"yax")==0)
			   S+=180;
			else if(strcmp(NOM,"zac")==0)
			   S+=200;
			else if(strcmp(NOM,"ceh")==0)
			   S+=220;
			else if(strcmp(NOM,"mac")==0)
			   S+=240;
			else if(strcmp(NOM,"kankin")==0)
			   S+=260;
			else if(strcmp(NOM,"muan")==0)
			   S+=280;
			else if(strcmp(NOM,"pax")==0)
			   S+=300;
			else if(strcmp(NOM,"koyab")==0)
			   S+=320;
			else if(strcmp(NOM,"cumhu")==0)
			   S+=340;
			else if(strcmp(NOM,"uayet")==0)
			   S+=360; 
			S+=NOTD+365*NOTY+1;
			return S;
		}
		~haab()
		{
			delete []NOM;
		}
};
class Tzolkin
{
	private:
	int year;
	int period;
	char NOP[9];
	public:
	Tzolkin(int N)
	{
		int a;
		int LeftDay;
		year=(N-1)/260;
		LeftDay=N-year*260;
		int numberofP=(LeftDay-1)/20;
		LeftDay=LeftDay-numberofP*20;
		numberofP++;
		if(numberofP%2)
		   a=(numberofP+1)/2;
		else
		   a=7+numberofP/2;
		if(LeftDay==1)
		   strcpy(NOP,"imix");
		else if(LeftDay==2)
		   strcpy(NOP,"ik");
		else if(LeftDay==3)
		   strcpy(NOP,"akbal");
		else if(LeftDay==4)
		   strcpy(NOP,"kan");
		else if(LeftDay==5)
		   strcpy(NOP,"chicchan");
		else if(LeftDay==6)
		   strcpy(NOP,"cimi");
		else if(LeftDay==7)
		   strcpy(NOP,"manik");
		else if(LeftDay==8)
		   strcpy(NOP,"lamat");
		else if(LeftDay==9)
		   strcpy(NOP,"muluk");
		else if(LeftDay==10)
		   strcpy(NOP,"ok");
		else if(LeftDay==11)
		   strcpy(NOP,"chuen");
		else if(LeftDay==12)
		   strcpy(NOP,"eb");
		else if(LeftDay==13)
		   strcpy(NOP,"ben");
		else if(LeftDay==14)
		   strcpy(NOP,"ix");
		else if(LeftDay==15)
		   strcpy(NOP,"mem");
		else if(LeftDay==16)
		   strcpy(NOP,"cib");
		else if(LeftDay==17)
		   strcpy(NOP,"caban");
		else if(LeftDay==18)
		   strcpy(NOP,"eznab");
		else if(LeftDay==19)
		   strcpy(NOP,"canac");
		else if(LeftDay==20)
		   strcpy(NOP,"ahau");
		period=(a+LeftDay-2)%13+1;
		
	 } 
	 void show()
	 {
	 	cout<<period<<' '<<NOP<<' '<<year<<endl;
	 }
} ;
int main()
{
	int N;
	cin>>N;
	int *a,*b;
	a=new int[N];
	b=new int[N];
	char *p;
	cout<<N<<endl;
   for(int i=0;i<N;i++)
   {
		cin>>a[i];
		cin.get();
		p=new char[7];
		cin>>p;
		cin>>b[i];
		haab A(a[i],p,b[i]);
		delete []p;
		Tzolkin B(A.calculate());
		B.show();
	}
	return 0;
}
