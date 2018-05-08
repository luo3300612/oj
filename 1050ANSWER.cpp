/*本题的求解思路
问题定性：动态规划问题
解决方法：逐层DP
思路：
	将问题转化为一维的求最长子列问题，对起始行和终止行进行遍历，同时保存同起始行上一次的计算结果，减少时间复杂度 
	  
	  
	  结果：16MS 328K 
 */
#include<iostream>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int rec[MAX]={0};
int main(){
	int n;
	int cumSum;
	int mx=-99999;
	cin>>n;
	for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		cin>>D[i][j];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==i){
				for(int k=1;k<=n;k++){
					rec[k]=D[i][k];
				}
				cumSum=0;
				for(int ii=1;ii<=n;ii++){
					if(cumSum<0){
						cumSum=rec[ii];
					}
					else{
						cumSum=cumSum+rec[ii];
					}
					if(cumSum>mx)
					mx=cumSum;
				}	
			}
			else{
				for(int k=1;k<=n;k++){
					rec[k]=rec[k]+D[j][k];
				}
				cumSum=0;
				for(int ii=1;ii<=n;ii++){
					if(cumSum<0){
						cumSum=rec[ii];
					}
					else{
						cumSum=cumSum+rec[ii];
					}
					if(cumSum>mx)
					mx=cumSum;
				}
				
			}
		}
	}
	cout<<mx<<endl;
} 
