#include<iostream>
#include<string>
using namespace std;
#define MAX 5001
char str1[MAX];
char str2[MAX]; 
int maxLen[2][MAX];
int len;
int main(){
	cin>>len;
	while(cin.get()!='\n'){
	}
	cin.getline(str1,len+1);
	for(int i=0;i<len;i++)
	str2[i]=str1[len-i-1];
	str2[len]='\0';
			maxLen[0][0]=0;
		for (int j=0;j<=len;j++){
			maxLen[0][j]=0;
		} 
		for(int i=1;i<=len;i++){
			for(int j=1;j<=len;j++){
				if ( str1[i-1] == str2[j-1] )
    				maxLen[i%2][j] = maxLen[(i-1)%2][j-1] + 1;   
				else    
    				maxLen[i%2][j] = max(maxLen[i%2][j-1],maxLen[(i-1)%2][j]);   
			}
		}
		cout<<len-maxLen[len%2][len]<<endl;
} 
