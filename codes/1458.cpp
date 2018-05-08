#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
int maxLen[1000][1000];
using namespace std;
int main(){
	string str1,str2;
	while(cin>>str1){
		cin>>str2;
		int len1=str1.length();
		int len2=str2.length();
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
		cout<<maxLen[len1][len2]<<endl;
	} 
} 
