#include<iostream>
#include<map>
using namespace std;
void delxiegang(string &s){
    int len=s.length();
    int index1=0;
    int flag=0;
    string ss;
    while(index1<len){
        if(flag==0&&s[index1]=='\\'){
            index1++;
            flag=1;
            continue;
        }
        flag=0;
        ss= ss + s[index1++];
    }
    s=ss;
}
int main(){
    string s1,s2,s3;
    cout<<s1.length()<<endl;
    
    /*cout<<s1.length()<<endl;
    int i;
    for(i=0;s1[i]!='\0';i++){

    }
    cout<<i<<endl;*/


    /*map<int,string> m1;
    m1.insert(pair<int,string>(2,"ssss"));
    cout<<m1[2]<<endl;
    map<int,string>::iterator tofind;
    tofind=m1.find(2);
    m1.erase(tofind);
    m1.insert(pair<int,string>(2,"aassss"));
    cout<<m1[2]<<endl;*/
    
}