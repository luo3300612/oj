#include<iostream>
using namespace std; 
int timemark[21];        //每次搜索时，对数字是否可选的标记 
int N;					//输入数字的个数 
int a[21];				//储存输入的数字 
int record[524288];		//保存局面策略的数组 
int cifang(int m,int n){//求m的n次方 
	if(n==0)
	return 1;
	int s=m;
	for(int i=1;i<n;i++)
		s=s*m;
	return s;
}
int bin2dec(int c[],int n){//将数组c对应的局面2进制数转化为十进制数字 
	int s=0;
	for(int i=1;i<=n;i++){
		s=s+cifang(2,c[i]-2);
	}
	return s;
}
int pd(int a[],int n){	//a是储存当前局面数字的数组，n是数组的长度 
	int b2d=bin2dec(a,n);	//求这个局面对应的十进制索引 
	if(record[b2d]!=0){		//如果是已搜索过的局面，则直接返回结果 
		return record[b2d];
	}
	else{//否则对这个局面开始搜索 
		int winmove[21];//储存胜利策略的数组 
		int winCount=1;//储存胜利策略的数量 
			int flag=0;//标记是否为必胜局面的变量，0必输，1必胜 
			for(int i=1;i<=n;i++){//循环取出a中第i个数字 
				int count=1;//取出数字的个数 
				for(int ii=2;ii<=20;ii++){//标记若数字t在数组a中，则标记为1，否则为0，去掉第i个元素，所以timemark[i]=0 
					timemark[ii]=0;
				}
				for(int ii=1;ii<=n;ii++){
					if(ii==i)
					continue;
					timemark[a[ii]]=1;
				}	
				for(int k=2;a[i]+k<=20;k++){//将因为第i个数字被取出而影响的数字剔除 
						if(timemark[k]==0&&timemark[a[i]+k]!=0){
							count++;
							timemark[a[i]+k]=0;
						}
				}
				int b[21];//储存a去掉取出的数字和受影响的数字后的数组，用来进行下一层搜索 
				for(int indb=1;indb<=n-count;){
					for(int inda=1;inda<=n;inda++){
						if(timemark[a[inda]]==1){
							b[indb]=a[inda];
							indb++;
						}
					}
				}
				int next=pd(b,n-count);//求下一层局面的胜负情况 
				if(next==-1){//如果下一层为必输局面，这一层就是必胜局面，同时当前取出的数字成为一个必胜策略 
					winmove[winCount++]=a[i];
					flag=1;
				}
				if(i==n&&flag==0){//遍历本次所有可取的数字后，记录输赢的标记flag为0，则说明无论取哪个数字，下一个局面都是一个必胜局面，从而当前局面为必输局面 
					record[bin2dec(a,n)]=-1;
					return -1;
				}
				else if(i==n&&flag==1){//遍历本次所有可取的数字后，记录输赢的标记flag为0，从而当前局面为必赢局面 
					record[bin2dec(a,n)]=bin2dec(winmove,winCount-1);//将必胜策略转化为十进制数字储存在record中 
					return 1;
				}
				}
			}
			
		}
void printWin(int t){//打印必胜时的策略 
	int count = 2;
	while(t!=0){
		if(t%2==1)
			cout<<count<<' ';
		count++;
		t=t/2;
	}
	cout<<endl;
}
int main(){
	cin>>N;
	int count=1;
	record[0]=-1;
	for(int i=1;i<524288;i++){
		record[i]=0;
	}
	for(int i=2;i<=20;i++){
		int a[2];
		a[1]=i;
		record[bin2dec(a,1)]=bin2dec(a,1);
	}
	while(N){
		for(int i=1;i<=N;i++)
		cin>>a[i];
		cout<<"Test Case #"<<count++<<endl;
		if(N==1){
			cout<<"The winning moves are: "<<a[1]<<endl;
		}
		else{
			int t=pd(a,N);
			if(t==-1)
				cout<<"There's no winning move."<<endl;
			else{
				cout<<"The winning moves are: ";
				printWin(record[bin2dec(a,N)]);
			}
		}
		cout<<endl;
		cin>>N;
	}
	return 0;
}
