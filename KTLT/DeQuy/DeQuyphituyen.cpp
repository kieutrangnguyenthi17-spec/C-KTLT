#include<iostream>
using namespace std;
int TinhX(int n){
    int tong;
    if (n==0) return 1;
    for(int i=0;i<n;i++){
        tong+=(n-i)*(n-i)*TinhX(i);
    }
    return tong;
}
int main(){
    int n;
    cin>>n;
    int kq=TinhX(n);
    cout<<"Tong: "<<kq;
    return 0;
}