#include<iostream>
using namespace std;
void nhap(int a[], int n){
    cout<<"Nhap mang:";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
int found(int a[], int x, int right, int left){
    if(left>right) return 1;
    int mid=(left+right)/2;
    if(a[mid]==x){
        return mid;
    }
    if(a[mid]<x) return found(a,mid+1,right,x);
    else return found(a,left,mid-1,x);
}
int main(){
    int n;
    cin>>n;
    int a[1000];
    nhap(a,n);
    int x, right,left;
    cin>>x;
    int kq= found(a,x,right,left);
    cout<<"Vi tri:"<<kq;
    return 0;
}