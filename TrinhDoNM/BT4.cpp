// Viết chương trình tìm nhị phân (viết đệ quy)
#include<iostream>
using namespace std;
int BinarySearch(int a[], int left, int right, int n, int x){
    if (left>right) return -1;
    int mid=(left+right)/2;
    if(a[mid]==x) return mid;
    if(a[mid]>x) return BinarySearch(a,left,right-1,n,x);
    else return BinarySearch(a,left+1, right, n,x);
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
    int x;
    cin>>x;
    int result=BinarySearch(a,0, n-1,n,x);
    cout<<"Vi Tri: "<<result;
    return 0;
} 