#include<iostream>
using namespace std;
int Fibonaci(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return Fibonaci(n-1)+Fibonaci(n-2);
}
int FibonaciArray(int n)
{
    if (n == 0 || n == 1) return 1;
    int a[1000];
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2];
    return a[n];
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int result=Fibonaci(n);
    cout<<result;
    int result1=FibonaciArray(n);
    cout<<"\n"<<result1;
    return 0;
}