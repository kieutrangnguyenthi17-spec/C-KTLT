#include<iostream>
using namespace std;
double Tong(int n){
    if (n==1) return 1.0/(1*2*3);
    return Tong(n-1)+1.0/(n*(n+1)*(n+2));
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    double result=Tong(n);
    cout<<"Tong "<<": "<<result;
    return 0;
}