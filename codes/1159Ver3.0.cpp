#include<iostream>
#include<string>
using namespace std;
#define MAX 5001
char str1[MAX];
char str2[MAX]; 
int maxLen[MAX][MAX];
int len;
int main(){
	cin>>len;
	while(cin.get()!='\n'){
	}
	cin.getline(str1,len+1);
	for(int i=0;i<len;i++)
	str2[i]=str1[len-i-1];
	str2[len]='\0';
	
	int last=0;
	int now=1;
	int t;
	int len1=len;
	int len2=len;
		for (int i=0;i<=len1;i++){
			maxLen[i][0]=0;
		}
		for (int j=0;j<=len2;j++){
			maxLen[0][j]=0;
		} 
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if ( str1[i-1] == str2[j-1] ) //s1µÄ×î×ó±ß×Ö·ûÊÇs1[0]     
    				maxLen[i][j] = maxLen[i-1][j-1] + 1;   
				else    
    				maxLen[i][j] = max(maxLen[i][j-1],maxLen[i-1][j]);   
			}
		}
		cout<<len-maxLen[len1][len2]<<endl;
} 
