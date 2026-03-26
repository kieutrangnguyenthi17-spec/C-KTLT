#include<iostream>
#include<string>
using namespace std;
string nhiphan_dq(int n){
    if(n<2) return to_string(n);
    return nhiphan_dq(n/2)+to_string(n%2);
}
string nhiphan(int n){
    string binary="";
    unsigned int temp=n;
    while(temp>0){
        int bit=temp%2;
        binary=char('0'+bit)+binary;
        temp=temp/2;
    }
    return binary;

}
int main(){
    int n;
    cin>>n;
    string result=nhiphan_dq(n);
    cout<<result;
    string result1=nhiphan(n);
    cout<<"\nTT: "<<result1;
    return 0;
}