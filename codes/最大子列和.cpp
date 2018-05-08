#include<iostream>
using namespace std; 
#define MAX 100000
int main (void)
{
    int N;
    cin>>N;

    int A[MAX];
    int i;
    for ( i = 0; i < N; i++){
        cin>>A[i];
    }
    int ans = A[0];
    int temp = 0;

    for ( i = 0; i < N; i++)
	{
        temp += A[i];
        if ( temp > ans){
            ans = temp;
        }else if ( temp < 0){
            temp = 0;
        }
    }
    
    cout<<ans<<endl;

    return  0;
}

