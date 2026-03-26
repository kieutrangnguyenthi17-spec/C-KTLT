// Tạo ra 1 mảng gồm 10 số ngẫu nhiên và trả về con trỏ vào mảng đó 
//KHÔNG DÙNG CON TRỎ
#include<iostream>
#include<ctime>
#include <cstdlib>

using namespace std;
void rand_number(int a[], int n){
   srand((unsigned) time (NULL));
   for (int i=0;i<n;i++){
    a[i]=rand();
   }
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Mang:" << a[i] << endl;
    }
    cout << "Phan tu dau tien = " << a[0] << endl;

    return 0;
}