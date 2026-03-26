#include<iostream>
using namespace std;
int power(int n, int exp){
    if(exp==0) return 1;
        return n*power(n,exp-1);
} 
int Tong(int n){
    if (n==1) return 1;
    return power(n,n)+Tong(n-1);
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int result=Tong(n);
    cout<<"Tong "<<": "<<result;
    return 0;
}