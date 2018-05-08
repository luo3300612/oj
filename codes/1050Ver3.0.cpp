/*本题的求解思路
问题定性：动态规划问题
解决方法：逐层DP
思路：1.先对位置遍历，再对矩形大小遍历
		2.先对矩形大小遍历，再对位置遍历
	  选择思路1，为了降低时间复杂度和空间复杂度，储存所有宽为1长为m的向量用来减少重复运算
	  从矩阵的右下角开始遍历，这样对左边的位置进行矩形大小向右扩张时，可以利用右边的计算结果
	  
	  
	  
	  结果：250MS 4368K 
	  更好的方法见1050ANSWER 
 */
#include<iostream>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int N;
int recn1[MAX][MAX][MAX];
int Ceng[MAX][MAX];
int main(){
	int flag=0;
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			cin>>D[i][j];
		}
	int mx=-99999;
	int sum;
	for(int i=N;i>=1;i--){
		for(int j=N;j>=1;j--){
			for(int m=1;i+m-1<=N;m++){
				for(int n=1;j+n-1<=N;n++){
					if(m==1&&n==1){
						recn1[i][j][m]=D[i][j];
						Ceng[m][n]=D[i][j];
						if(D[i][j]>mx)
						mx=D[i][j];
						continue;	
					}
					if(n==1){
						recn1[i][j][m]=recn1[i][j][m-1]+D[i+m-1][j];
						if(recn1[i][j][m]>mx)
						mx=recn1[i][j][m];
						Ceng[m][n]=recn1[i][j][m];
						continue;
					}
					if(j==N){
						sum=0;
						for(int t1=i;t1<=i+m-1;t1++){
							sum=sum+D[t1][j];
						}
						Ceng[m][n]=sum;
						if(Ceng[m][n]>mx)
						mx=Ceng[m][n];
						continue;
					}
					Ceng[m][n]=Ceng[m][n-1]+recn1[i][j+n-1][m];				
					if(Ceng[m][n]>mx)
						mx=Ceng[m][n];				 
				}
			}
		}
	}
	cout<<mx<<endl;
} 

/*输入
4
0 -2 -7 0 
9 2 -6 2
-4 1 -4 1 
-1 8  0 -2 



*/ 
