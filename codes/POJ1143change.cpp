#include<iostream>
using namespace std; 
int timemark[21];
int N;
int a[21];
int record[524288];
int numRec[20];
int cifang(int m,int n){
	if(n==0)
	return 1;
	int s=m;
	for(int i=1;i<n;i++)
		s=s*m;
	return s;
}
int bin2dec(int c[],int n){
	int s=0;
	for(int i=1;i<=n;i++){
		s=s+cifang(2,c[i]-2);
	}
	return s;
}
int pd(int a[],int n){
	int b2d=bin2dec(a,n);
	if(record[b2d]!=0){
		return record[b2d];
	}
	if(n==1){
		return 1;
	}
	else if(n==0){
		return -1;
	}
	else{
		int winmove[21];
		int winCount=1;
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
				for(int k=2;a[i]+k<=20;k++){
						if(timemark[k]==0&&timemark[a[i]+k]!=0){
							count++;
							timemark[a[i]+k]=0;
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
				if(i==n&&flag==0){
					record[bin2dec(a,n)]=-1;
					return -1;
				}
				else if(i==n&&flag==1){
					record[bin2dec(a,n)]=bin2dec(winmove,winCount-1);
					return 1;
				}
				}
			}
			
		}
void printWin(int t){
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
