#include<iostream>
using namespace std;
void Nhap(int a[], int n){
    cout<<"Nhap mang: ";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
// từ sau ra trước
void old(int a[], int n){
    if (n==0) return;
    if(a[n-1]%2!=0) {
        cout<< a[n-1]<<" ";
    }
    old(a,n-1);
}
// từ trước ra sau
void old1(int a[], int n){
    if (n==0) return;
    old(a,n-1);
    if(a[n-1]%2!=0) {
        cout<< a[n-1]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int a[1000];
    Nhap(a,n);
    cout<<"Day le: "<<"\n";
    old(a,n);
    cout<<"\nDay le1: "<<"\n";
    old1(a,n);
    return 0;
}
