/*336K 797MS*/
#include<iostream>
#include<string>
using namespace std;
#define MAX 5001
char str[MAX];
int maxLen[2][MAX];
int len;
int main(){
	cin>>len;
	while(cin.get()!='\n'){
	}
	cin.getline(str,len+1);
	int last=0;
	int now=1;
	int t;
	maxLen[0][0]=0;
	for (int j=0;j<=len;j++){
		maxLen[0][j]=0;
	} 
	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++){
			if ( str[i-1] == str[len-j] ) //s1µÄ×î×ó±ß×Ö·ûÊÇs1[0]     
    			maxLen[now][j] = maxLen[last][j-1] + 1;   
			else    
    			maxLen[now][j] = max(maxLen[now][j-1],maxLen[last][j]);   
		}
		t=now;
		now=last;
		last=t;
	}
	cout<<len-maxLen[last][len]<<endl;
	
} 
