#include<iostream>
using namespace std;
// int foo(int n) { 
// if (n < 10) 
// return 1; 
// return 1 + foo(n / 10); 
// } 
int foo_non(int n) {
    int count = 0;
    do {
        count++;
        n = n / 10;
    } while (n > 0);

    return count;
}
int main(){
    cout<<"Nguyen Thi Kieu Trang"<<endl;
    cout<<"MSSV: 24133064"<<endl;
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int result=foo_non(n);
    cout<<result<<endl;
    return 0;
}
