#include<iostream>
using namespace std;
float sum(int n){
    if (n==1) return 1;
    return 1.0f/n+sum(n-1);
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    float result=sum(n);
    cout<<"Tong nghich dao cua day "<<n<<": "<<result;
    return 0;
}