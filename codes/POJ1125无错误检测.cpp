#include<iostream>
#include<algorithm> 
#define MAX 101
int in[MAX][MAX];
int shortestRoute[MAX];
int n;
using namespace std;
void dijkstra(int st){
	for(int i=1;i<=n;i++){
		shortestRoute[i]=10000;
	}
	shortestRoute[st]=0;
	bool mark[MAX];
	for(int i=1;i<=n;i++)
	mark[i]=false;
	mark[st]=true;
	int flag=0;
	for(int i=1;i<=n;i++){
		if(mark[i]==false){
			flag=1;
			break;
		}
	}
	while(flag){
		int minn=100000;
		int nextRec;
		for(int i=1;i<=n;i++){
			if(mark[i]==false){
				for(int j=1;j<=n;j++){
					if(in[j][i]<=10)
					shortestRoute[i]=min(shortestRoute[i],shortestRoute[j]+in[j][i]);
				}
			if(shortestRoute[i]<minn){
				minn=shortestRoute[i];
				nextRec=i; 
				}
			}
		}
		mark[nextRec]=true;
		flag=0;	
		for(int i=1;i<=n;i++){
			if(mark[i]==false){
				flag=1;
				break;
			}
		}
		
	}
}
int main(){
	cin>>n;
	while(n!=0){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j){
				in[i][j]=0;
				continue;
			}
			in[i][j]=11;
		}
	int num;
	int target;
	int time;
	int count=1;
	while(count<=n){
		cin>>num;
		while(num--){
			cin>>target;
			cin>>time;
			in[count][target]=time;
		}
		count++;
	}
	int mx[MAX];
	for(int i=1;i<=n;i++){
		dijkstra(i);
		mx[i]=0;
		for(int j=1;j<=n;j++){
			if(shortestRoute[j]>mx[i])
				mx[i]=shortestRoute[j];
		}
	}
	int mi=10000;
	int rc=0;
	for(int i=1;i<=n;i++){
		if(mx[i]<mi){
			mi=mx[i];
			rc=i;
		}
	}
	if(mi!=10000)
	cout<<rc<<' '<<mi<<endl;
	else
	cout<<"disjoint"<<endl;
	cin>>n;
	}
}
