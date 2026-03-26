#include<iostream>
using namespace std;
void rotateright(int arr[], int n, int k ){
    if(k%n==0) return;
    int temp[1000];
    for(int i=0;i<k;i++){
        temp[i]=arr[n-k+i];
    }
    for(int i=n-1;i>=k;i--){
        arr[i]=arr[i-k];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
}
void Nhapmang(int arr[], int n){
    cout<<"Nhap mang: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int main(){
    cout<<"Nguyen Thi Kieu Trang"<<endl;
    cout<<"MSSV: 24133064"<<endl;
    int n,k;
    cout<<"Nhap n: ";
    cin>>n;
    int arr[1000];
    Nhapmang(arr,n);
    cout<<"Nhap k: "<<endl;
    cin>>k;
    rotateright(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}