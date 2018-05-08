#include<iostream>
using namespace std;
int mark[21]; 
int number[21];
int nowmark[21];
int timemark[21];
int N;
int a[21];
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
				int count=1;
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
									count++;
									timemark[a[j]]=0;
									break;
								}
								if(timemark[l]==0&&(a[j]-k*a[i])%l==0){
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
				for(int indb=1;indb<=n-count;){
					for(int inda=1;inda<=n;inda++){
						if(timemark[a[inda]]==1){
							b[indb]=a[inda];
							indb++;
						}
					}
				}
				
				int next=pd(b,n-count);
				if(next==-1){
					winmove[winCount++]=a[i];
					flag=1;
				}
				if(n!=N&&flag==1){
					return 1;
				}
				if(i==n&&flag==0){
					if(n==N){
						cout<<"There's no winning move."<<endl;
					}
					return -1;
				}
				else if(i==n&&flag==1){
					if(n==N){
						cout<<"The winning moves are: ";
						for(int xii=1;xii<winCount;xii++)
						cout<<winmove[xii]<<' ';
						cout<<endl;
					}
					return 1;
				}
				
				}
			}
			
		}
int main(){
	cin>>N;
	int count=1;
	while(N){
		for(int i=1;i<=N;i++)
		cin>>a[i];
		cout<<"Test Case #"<<count++<<endl;
		if(N==1){
			cout<<"The winning moves are: "<<a[1]<<endl;
		}
		else{
			pd(a,N);
		}
		
		cin>>N;
	}
	return 0;
}
