//Tìm giá trị nhỏ nhất của các phần tử trong một mảng một chiều.
#include<iostream>
using namespace std;
int min(int a[], int n){
    int minnum=a[0];
    for(int i=1;i<n;i++){
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
    int result=min(a,n);
    cout<<"Gia tri nho nhat: "<<result;
    return 0;
} 