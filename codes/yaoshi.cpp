#include<iostream>
using namespace std;
int N;
int K;
int key[1001];
int getkey[1001][2];
int returnkey[1001][2];
void BubbleSort(int A[][2],int len){
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len-i;j++){
            if(A[j][1]>A[j+1][1]){
                int tmp=A[j][1];
                A[j][1]=A[j+1][1];
                A[j+1][1]=tmp;
                tmp=A[j][0];
                A[j][0]=A[j+1][0];
                A[j+1][0]=tmp;
            }
            else if(A[j][1]==A[j+1][1]){
                if(A[j][0]>A[j+1][0]){
                    int tmp=A[j][1];
                    A[j][1]=A[j+1][1];
                    A[j+1][1]=tmp;
                    tmp=A[j][0];
                    A[j][0]=A[j+1][0];
                    A[j+1][0]=tmp;
                }
            }
        }
    }
}
int main(){
    cin>>N>>K;
    int count=1;
    int copyK=K;
    while(copyK--){
        cin>>getkey[count][0]>>getkey[count][1]>>returnkey[count][1];
        returnkey[count][1]+=getkey[count][1];
        returnkey[count][0]=getkey[count][0];
        count++;
    }
    BubbleSort(getkey,K);
    BubbleSort(returnkey,K);
    
    int getindex,returnindex;
    getindex=1;
    returnindex=1;
    for(int i=1;i<=N;i++){
        key[i]=i;
    }
    while(getindex<=K||returnindex<=K){
        while((returnkey[returnindex][1]<=getkey[getindex][1]||getindex>K)&&returnindex<=K){
            for(int i=1;i<=N;i++){
                if(key[i]==0){
                    key[i]=returnkey[returnindex][0];
                    cout<<"return key "<<returnkey[returnindex][0]<<" at "<<returnkey[returnindex][1]<<endl;
                    break;
                }
            }
            returnindex++;
            cout<<returnindex<<endl;
        }
        while((returnkey[returnindex][1]>getkey[getindex][1])&&getindex<=K){
            for(int i=1;i<=N;i++){
                if(key[i]==getkey[getindex][0]){
                    key[i]=0;
                    cout<<"get key "<<getkey[getindex][0]<<" at "<<getkey[getindex][1]<<endl;
                }
            }
            getindex++;
        }
    }
    for(int i=1;i<=N;i++){
        cout<<key[i];
    }
    cout<<endl;
    /*
    cout<<"get"<<endl;
    for(int i=1;i<=K;i++){
        cout<<getkey[i][0]<<' '<<getkey[i][1]<<endl;
    }
    cout<<"return"<<endl;
    for(int i=1;i<=K;i++){
        cout<<returnkey[i][0]<<' '<<returnkey[i][1]<<endl;
    }*/
}
/*
5 7
1 1 14
3 3 12
2 7 20
1 15 12
3 18 12
4 21 19
5 30 9

*/