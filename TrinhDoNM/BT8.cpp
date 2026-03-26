// Tìm số nguyên tố nhỏ nhất trong mảng.
#include<iostream>
#include<cmath>
using namespace std;
bool SNT(int n){
    if (n<2) return false;
    for(int i=2;i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}
int min(int a[], int n){
    int minnum=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<minnum){
            minnum=a[i];
        }
    }
    return minnum;
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
    int snt[100];
    int k=0;
    for(int i=0;i<n;i++){
        if(SNT(a[i])){
            snt[k]=a[i];
            k++;
        }
    }
    int result=min(snt,k);
    cout<<"So nguyen to nho nhat: "<<result;
    return 0;
} 