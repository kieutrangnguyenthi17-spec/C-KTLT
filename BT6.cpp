// Tính giá trị phần tử thứ n của dãy Fibonacci (không dùng mảng)
#include<iostream>
using namespace std;
long long Fibonacci(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}
int main(){
    int n;
    cin>>n;
    int result=Fibonacci(n);
    cout<<"Tong day Fibonacci: "<<result;
    return 0;
}