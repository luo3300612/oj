#include<iostream>
using namespace std;
int mark[21]; 
int number[21];
int nowmark[21];
int timemark[21];
int N;
int pd(int a[],int n){
	
	
	
	if(n==1){
		return 1;
	}
	else if(n==0){
		return -1;
	}
	else{
		int winmove[21];
		int winCount=1;
		for(int i=2;i<=20;i++){
			nowmark[i]=0;
		}
		for(int i=1;i<=n;i++){
			nowmark[a[i]]=1;
		}
			int flag=0;
			for(int i=1;i<=n;i++){
				cout<<"origin:";
				for(int ii=1;ii<=n;ii++){
					cout<<a[ii]<<' ';
				}
				cout<<endl;
				int count=1;
				cout<<"Now remove "<<a[i]<<" :"<<endl;
				for(int ii=2;ii<=20;ii++){
					timemark[ii]=0;
				}
				for(int ii=1;ii<=n;ii++){
					if(ii==i)
					continue;
					timemark[a[ii]]=1;
				}	
				for(int j=1;j<=n;j++){
					if(j!=i){
						for(int k=1;a[j]-k*a[i]>=0;k++){
							for(int l=2;l<=20;l++){
								if(a[j]-k*a[i]==0){
									cout<<"number "<<a[j]<<" is removed because "<<a[j]<<"-"<<k<<"¡Á"<<a[i]<<"=0"<<endl;
									count++;
									timemark[a[j]]=0;
									break;
								}
								if(timemark[l]==0&&(a[j]-k*a[i])%l==0){
									cout<<"number "<<a[j]<<" is removed because ("<<a[j]<<"-"<<k<<"¡Á"<<a[i]<<")%"<<l<<"=0"<<endl;
									count++;
									timemark[a[j]]=0;
									break;
								}
							}
							if(timemark[a[j]]==0)
								break;
						}
					}
				}
				int b[21];
				cout<<"after:";
				for(int indb=1;indb<=n-count;){
					for(int inda=1;inda<=n;inda++){
						if(timemark[a[inda]]==1){
							b[indb]=a[inda];
							cout<<b[indb]<<' '; 
							indb++;
						}
					}
				}
				cout<<endl;
				
				int next=pd(b,n-count);
				if(next==-1){
					winmove[winCount++]=a[i];
					cout<<"win move "<<a[i]<<"winCount "<<winCount<<endl;
					flag=1;
				}
				if(i==n&&flag==0){
					if(n==N){
						cout<<"state :"<<endl;
						for(int xi=1;xi<=n;xi++){
							cout<<a[xi]<<' ';
						}
						cout<<" is a losing state"<<endl;
					}
					return -1;
				}
				else if(i==n&&flag==1){
					if(n==N){
						cout<<"state :"<<endl;
						for(int xi=1;xi<=n;xi++){
							cout<<a[xi]<<' ';
						}
						cout<<" is a winning state because we can remove "<<endl;;
						for(int xii=1;xii<winCount;xii++)
						cout<<winmove[xii]<<' ';
						cout<<" to win"<<endl;
					}
					return 1;
				}
				
				}
			}
			
		}
int main(){
	int a[7];
	a[1]=2;
	a[2]=3;
	a[3]=4;
	a[4]=5;
	a[5]=6;
	a[6]=7;
	pd(a,6);
	return 0;
}
