#include<iostream>
using namespace std;
int CongDay(int n){
    if(n==0) return 0;
    return n+CongDay(n-1);
}
int main(){
    int n;
    cin>>n;
    int kq=CongDay(n);
    cout<<"KQ: "<<kq;
    return 0;
}