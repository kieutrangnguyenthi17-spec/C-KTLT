//Tìm một số trong một mảng đã có thứ tự( bằng nhị phân)
//Nếu bằng → tìm thấy.
// Nếu X nhỏ hơn → bỏ nửa bên phải, chỉ tìm bên trái.
// Nếu X lớn hơn → bỏ nửa bên trái, chỉ tìm bên phải.

#include<iostream>
using namespace std;
int BinarySearch(int a[], int n, int x){
    int left=0;
    int right=n-1;
    while (left<=right){
        int mid=(left+right)/2;
        if (a[mid]==x){
            return mid;
        } else 
            if(a[mid]>x)
                right=mid-1;
            else left=mid+1;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Nhap n:";
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cout<<"Nhap x: ";
    cin>>x;
    int result=BinarySearch(a,n,x);
    if (result==-1){
        cout<<"Khong tim thay!";
    } else cout<<"Vi tri: "<<result;
    return 0;
}