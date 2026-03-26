#include<iostream>
using namespace std;
int sum(int n){
    if (n==1) return 1;
    return n*n+sum(n-1);
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int result=sum(n);
    cout<<"Tong luy thua 2 cua day "<<n<<": "<<result;
    return 0;
}