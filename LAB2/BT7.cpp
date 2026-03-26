// Viết hàm tính tổng các phần tử trong hai mảng.
// Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.
// In [ ]:
#include <iostream>
using namespace std;
template<typename T> // generic type
T arr_sum(T a[], int x, T b[], int y){
    T sumx=0;
    T sumy=0;
    for (int i=0;i < x;i++){
            sumx+=a[i];
    }
    for (int j=0;j<y;j++){
        sumy+=b[j];
    }
    return sumx+sumy;
}
int main() {
int val;
cin >> val;
{
int a[] = {3, 2, 0, val};
int b[] = {5, 6, 1, 2, 7};
cout << "Tong:" <<arr_sum(a, 4, b, 5) << endl;
}
{
double a[] = {3.0, 2, 0, val * 1.0};
double b[] = {5, 6.1, 1, 2.3, 7};
cout <<"Tong"<< arr_sum(a, 4, b, 5) << endl;
}
return 0;
}