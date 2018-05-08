#include<stdio.h>
using namespace std;
#define MAX 21 
#define dimension 2 
int classALL[MAX];
int oriClassB[MAX];
int lenA;
int lenB;
int time=0;//循环次数 
double lamda=0.1;//学习速率 
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
	printf("输入第一类点的个数\n");
	scanf("%d",&lenA);
	printf("输入第一类点的坐标\n");
	for(int i=1;i<=lenA;i++){
		scanf("%d %d",&x,&y);
		classALL[i]=encode(x,y);
	}
	printf("输入第二类点的个数\n");
	scanf("%d",&lenB);
	printf("输入第二类点的坐标\n");
	for(int i=1+lenA;i<=lenA+lenB;i++){
		scanf("%d %d",&x,&y);
		classALL[i]=encode(-x,-y);
		oriClassB[i]=encode(x,y);
	}
	
	
	weight[0]=decode1(classALL[1])*lamda;
	weight[1]=decode2(classALL[1])*lamda;
	int flag=1;
	while(flag){
		printf("第%d次学习开始,weight的两个分量是%lf,%lf\n",time,weight[0],weight[1]);
		flag=0;
		time++;
		for(int i=1;i<=lenA+lenB;i++){
			if(weight[0]*decode1(classALL[i])+weight[1]*decode2(classALL[i])<=0){
				flag++;
				weight[0]+=lamda*decode1(classALL[i]);
				weight[1]+=lamda*decode2(classALL[i]);
			}
		}
		printf("第%d次学习后，还有%d个点不满足,weight的两个分量是%lf,%lf\n",time,flag,weight[0],weight[1]);
	}
	printf("学习结束，weight的两个分量是%lf,%lf",weight[0],weight[1]);
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
