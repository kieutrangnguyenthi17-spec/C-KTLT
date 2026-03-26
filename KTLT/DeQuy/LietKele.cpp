#include<iostream>
using namespace std;
void Nhap(int a[], int n){
    cout<<"Nhap mang: ";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
void LietKeLe(int a[], int n)
{
if (n > 0)
{
LietKeLe(a, n - 1);
if (a[n - 1] % 2 != 0)
cout << a[n - 1] << " ";
}

}
int main(){
    int n;
    cin>>n;
    int a[1000];
    Nhap(a,n);
    LietKeLe(a,n);
    return 0;
}