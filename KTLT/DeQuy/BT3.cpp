#include<iostream>
using namespace std;
double Si(int i){
    if(i==1) return 1.0/2;
    return Si(i-1)/(2*i);
}
double Tong(int n){
    if (n==1) return 1.0/(1*2*3);
    return Tong(n-1)+Si(n);
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    double result=Tong(n);
    cout<<"Tong "<<": "<<result;
    return 0;
}