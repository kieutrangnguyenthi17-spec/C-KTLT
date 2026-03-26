#include<iostream>
using namespace std;
// PP thong thuong
int giaithua(int n){
    int gt=1;
    for (int i=1;i<n+1;i++){
        gt*=i;
    }
    return gt;
}
// De Quy
int GiaiThua(int n){
    if(n==1||n==0){
        return 1;
    }
    return n*giaithua(n-1);
}
int main(){
    int n;
    cin>>n;
    int result=giaithua(n);
    cout<<"Thong thuong:"<<result;
    int Result=GiaiThua(n);
    cout<<"\nDe Quy: "<<Result;
    return 0;
}