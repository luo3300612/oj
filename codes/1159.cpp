#include<iostream>
#include<string>
using namespace std;
string str;
int end;
int start=1;
int cal(int st,int ed){
	if(st>ed){
		return 0;
	}
		
	if(str[st]==str[ed])
		return cal(st+1,ed-1);
	if(str[st]!=str[ed]){
		return 1+min(cal(st+1,ed),cal(st,ed-1));
	}
}
int main(){
	cin>>end;
	cin>>str;
	int result=cal(0,end-1);
	cout<<result<<endl;
} 
