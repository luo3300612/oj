/*��������˼·
���ⶨ�ԣ���̬�滮����
������������DP
˼·��
	������ת��Ϊһά������������⣬����ʼ�к���ֹ�н��б�����ͬʱ����ͬ��ʼ����һ�εļ�����������ʱ�临�Ӷ� 
	  
	  
	  �����16MS 328K 
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
