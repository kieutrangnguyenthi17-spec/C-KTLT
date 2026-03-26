// Tìm phần tử có tần số xuất hiện nhiều nhất trong một mảng.
#include<iostream>
using namespace std;
int Count(int a[], int n){
    int maxcount=0;
    int k=a[0];
    for(int i=0;i<n;i++){
        int count=0;
        for (int j=0;j<n;j++){
            if(a[i]==a[j]) count++;
        }
        if(count>maxcount){
            maxcount=count;
            k=a[i];
        }
    }
    return k;
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
    int result=Count(a,n);
    cout<<"Phan tu xuat hien nhieu nhat: "<<result;
    return 0;
}