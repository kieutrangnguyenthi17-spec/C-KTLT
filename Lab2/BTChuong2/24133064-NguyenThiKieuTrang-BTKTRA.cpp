#include <iostream>
using namespace std;

// In kết quả
void inkq(int* arr, int* pair, int k, int count){
    cout << "\nCac cap (a, b) co tong bang " << k << ":\n";
    for(int i = 0; i < count; i += 2){
        int a = pair[i];      // chỉ số
        int b = pair[i + 1];  // chỉ số
        cout << "(" << *(arr + a) << ", " << *(arr + b)
             << ") tai chi so (" << a << ", " << b << ")\n";
    }
}

// Tìm cặp, dùng con trỏ
int tim(int* arr, int n, int k, int* pair){
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if( *(arr + i) + *(arr + j) == k ){   // dùng con trỏ
                pair[count++] = i;           // lưu chỉ số
                pair[count++] = j;
            }
        }
    }

    return count;     // trả về số phần tử trong pair[]
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;

    // cấp phát động
    int* arr = new int[n];

    cout << "Nhap " << n << " phan tu:\n";
    for(int i = 0; i < n; i++){
        cin >> *(arr + i);   // dùng con trỏ
    }

    int k;
    cout << "Nhap k: ";
    cin >> k;

    int maxsize = n * (n - 1);   // tối đa 2 chỉ số cho mỗi cặp
    int* pair = new int[maxsize];

    // Tìm cặp
    int count = tim(arr, n, k, pair);

    // In mảng ban đầu
    cout << "\nMang ban dau: ";
    for(int i = 0; i < n; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // In kết quả
    inkq(arr, pair, k, count);

    delete[] arr;
    delete[] pair;
    return 0;
}
