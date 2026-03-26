// Tìm UCLN của tất cả các phần tử trong mảng.
#include<iostream>
using namespace std;
int UCLN(int a, int b){
    if(b==0) return a;
    return UCLN(b,b%a);

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
    int k=a[0];
    for(int i=0;i<n;i++){
       int k = UCLN(k,a[i]);
    }
    cout<<"UCLN cua cac phan tu trong mang la: "<<k<<endl;
    return 0;
}