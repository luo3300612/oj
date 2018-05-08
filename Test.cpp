#include<stdio.h>
using namespace std;
#define MAX 21 
#define dimension 2 
int classA[MAX];
int classB[MAX];
int oriClassB[MAX];
int lenA;
int lenB;
double lamda;
double weight[dimension];
int encode(int a,int b){
	int s;
	if(a>=0){s=a;}
	if(a<0){s=-a;s|=1<<7;}
	if(b>=0){s<<=8;s|=b;}
	if(b<0){s<<=8;s|=-b;s|=1<<7;}
	return s;
}
int decode1(int s){
	s>>=8;
	if(s>>7==1){s&=~(1<<7);return -s;}
	else{return s;}
}
int decode2(int s){
	s&=~(((1<<8)-1)<<8);
	if(s>>7==1){s&=~(1<<7);return -s;}
	else{return s;}
}
int main(){
	int x,y;
	printf("�����һ���ĸ���\n");
	scanf("%d",&lenA);
	printf("�����һ��������\n");
	for(int i=1;i<=lenA;i++){
		scanf("%d %d",&x,&y);
		classA[i]=encode(x,y);
		printf("�������%d���������%d,%d\n",classA[i],decode1(classA[i]),decode2(classA[i]));
	}
	
	printf("����ڶ����ĸ���\n");
	scanf("%d",&lenB);
	printf("����ڶ���������\n");
	for(int i=1;i<=lenB;i++){
		scanf("%d %d",&x,&y);
		classB[i]=encode(-x,-y);
		oriClassB[i]=encode(x,y);
		printf("�������%d���������%d,%d\n",classB[i],decode1(classB[i]),decode2(classB[i]));
	}
	lamda=0.1;
	printf("ѧϰ֮ǰclassA1��%d��lamda��%lf,weight������������%lf,%lf\n",classA[1],lamda,decode1(classA[1])*lamda,decode2(classA[1])*lamda); 
	
	
	weight[0]=decode1(classA[1])*lamda;
	weight[1]=decode2(classA[1])*lamda;

	int flag=1;
	int time=0;
	while(flag){
		printf("��%d��ѧϰ,weight������������%lf,%lf\n",time,weight[0],weight[1]);
		flag=0;
		time++;
		for(int i=1;i<=lenA+lenB;i++){
			if(i<=lenA){
				int x=decode1(classA[i]);
				int y=decode2(classA[i]);
				if(weight[0]*x+weight[1]*y<=0){
					flag++;
					weight[0]+=lamda*x;
					weight[1]+=lamda*y;
				}
			}
			if(i>lenA){
				int x=decode1(classB[i-lenA]);
				int y=decode2(classB[i-lenA]);
				if(weight[0]*x+weight[1]*y<=0){
					flag++;
					weight[0]+=lamda*x;
					weight[1]+=lamda*y;
				}
			}
		}
		printf("��%d��ѧϰ������%d���㲻����,weight������������%lf,%lf\n",time,flag,weight[0],weight[1]);
	}
	printf("ѧϰ������weight������������%lf,%lf",weight[0],weight[1]);
}

/*
5
2 4
3 3
2 2
3 1
2 3
5
-1 -1
-3 -3
-2 -4
-2 1
-1 2





*/
