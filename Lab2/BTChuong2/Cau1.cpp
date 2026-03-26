//Tìm một số trong một mảng bằng lính canh. -> 1 phép ss/ vòng lặp
#include<iostream>
using namespace std;
int sentineSearch(int a[], int n, int key)
{
    // đặt lính canh
    a[n]= key;
    int i=0;
    while (a[i]!=key){
        i++; //kho
    }
    if(i<n){
        return i; }
    else return -1;
}
int main(){
    int n, key;
    cout<<"Nhap n:";
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Nhap key can tim: ";
    cin>>key;
    int result = sentineSearch(a, n, key);
    if (result==-1){
        cout<<"Khong tim duoc!";
    } else cout<<"vi tri tim thay: "<<result;
    return 0;
}