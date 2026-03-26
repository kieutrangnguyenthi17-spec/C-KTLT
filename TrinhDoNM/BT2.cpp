//Tính tổng các phần tử trong mảng một chiều.
#include<iostream>
using namespace std;
int Sum(int a[], int n){
    int Sumnum=0;
    for(int i=0;i<n;i++){
            Sumnum+=a[i];
    }
    return Sumnum;
}
void Nhapmang(int a[], int n){
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
int main(){
    int n;
    cin>>n;
    int a[1000];
    Nhapmang(a,n);
    int result=Sum(a,n);
    cout<<"Tong mang: "<<result;
    return 0;
} 