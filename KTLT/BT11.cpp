// Cài đặt các bài từ 1 đến 5 trong trình độ nhập môn bằng đệ quy.
#include<iostream>
using namespace std;
//Tìm giá trị nhỏ nhất của các phần tử trong một mảng một chiều.
int min(int a[], int n){
    if(n==1) return a[0];
    int minnum=min(a+1, n-1);
    return (a[0]<minnum)? a[0]:minnum;
}
//Tính tổng các phần tử trong mảng một chiều.
int Sum(int a[], int n, int index){
    if(index==n) return 0;
    return a[index]+Sum(a,n,index+1);
}
// Tính n!
int GiaiThua(int n){
    if(n==1) return 1;
    return n*GiaiThua(n-1);
}
// Viết chương trình tìm nhị phân (viết đệ quy)
int BinarySearch(int a[], int left, int right, int n, int x){
    if (left>right) return -1;
    int mid=(left+right)/2;
    if(a[mid]==x) return mid;
    if(a[mid]>x) return BinarySearch(a,left,right-1,n,x);
    else return BinarySearch(a,left+1, right, n,x);
}
// tính C(k, n)
long long ToHop(int n, int k){
    return GiaiThua(n)/(GiaiThua(k)*(GiaiThua(n-k)));
}

void Nhapmang(int a[], int n){
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
int main(){
    int n;
    int a[1000];
    cin>>n;
    Nhapmang(a,n);
    cout<<"Gia tri nho nhat trong mang: "<<min(a,n)<<endl;
    int index=0;
    cout<<"Tong mang: "<<Sum(a,n,index)<<endl;
    int x;
    cout<<"Nhap x:"<<endl;
    cin>>x;
    cout<<"Tim kiem nhi phan: "<<BinarySearch(a,0,n-1,n,x)<<endl;
    int k;
    cout<<"Nhap k:"<<endl;
    cin>>k;
    cout<<"To hop"<<" : "<<ToHop(n,k)<<endl;
    return 0;
}