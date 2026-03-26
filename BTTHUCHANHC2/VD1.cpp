#include<iostream>
using namespace std;
void array_sum(int n, int* ptr_a){
    int sum=0;
    for (int i=0;i<n;++i){
        sum+= *(ptr_a +i); // *(ptr_a+i)=a[i]
    }   cout<<"Tong cua mang: "<< sum<< endl;
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    // int a[n]; -> cách thông thường
    int* a=new int[n]; // -> con trỏ mảng/ mảng động
    cout<<"Nhap mang: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    array_sum(n,a);
    return 0;

}
