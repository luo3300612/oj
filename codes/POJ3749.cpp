#include<iostream>
using namespace std;
 int main()
 {
 	int N;
 	cin>>N;
 	if(N>=90)
 	cout<<'A'<<endl;
 	else if(N<90&&N>=80)
 	cout<<'B'<<endl;
 	else if(N<80&&N>=70)
 	cout<<'C'<<endl;
 	else if(N<70&&N>=60)
 	cout<<'D'<<endl;
 	else
 	cout<<'E'<<endl;
 	return 0;
 }
