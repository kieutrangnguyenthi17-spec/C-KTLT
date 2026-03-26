#include<iostream>
using namespace std;
void findMinMax(int *arr, int n, int *min, int *max){
    *min=*(arr+0);
    *max=*(arr+0);
    for (int i=0;i<n;i++){
        if(*(arr+i)>*max){
            *max=*(arr+i);
        }
        if(*(arr+i)<*min){
            *min=*(arr+i);
        }
    }
    cout<<"Min: "<<*min<<endl;
    cout<<"Max: "<<*max<<endl;
}
void Nhapmang(int *arr, int n){
    cout<<"Nhap mang: "<<endl;
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
}
int main(){
    cout<<"Nguyen Thi Kieu Trang"<<endl;
    cout<<"MSSV: 24133064"<<endl;
    int n;
    cout<<"Nhap n:";
    cin>>n;
    int min, max;
    int arr[1000];
    Nhapmang(arr,n);
    findMinMax(arr,n,&min, &max);
    return 0;
}