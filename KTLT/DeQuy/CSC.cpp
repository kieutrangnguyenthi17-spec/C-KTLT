// a=3, d=4
#include<iostream>
using namespace std;
int csc(int a, int d, int n){
    return a+(n-1)*d;
}
int csc_dq(int a, int d, int n){
    if(n==1) return a;
    return d+csc_dq(a,d,n-1);
}
int main(){
    int a;
    cin>>a;
    int n;
    cin>>n;
    int d;
    cin>>d;
    int result=csc(a,d,n);
    cout<<"Thong thuong:"<<result;
    int result_dq=csc(a,d,n);
    cout<<"\nDe quy: "<<result_dq;
    return 0;
}
