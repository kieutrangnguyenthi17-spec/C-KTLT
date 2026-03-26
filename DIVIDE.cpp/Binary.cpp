#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == key)
            return mid;   
        else if (key < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;  
}
void Nhapmang(int a[], int n)
{
    cout << "Nhap mang (da sap xep tang dan):\n";
        for (int i = 0; i < n; i++)
            cin >> a[i];
}
int main() {
    int n, key;

    cout << "Nhap so phan tu: ";
    cin >> n;

    int a[100];

    Nhapmang(a,n);
    cout << "Nhap gia tri can tim: ";
    cin >> key;

    int result = binarySearch(a, n, key);

    if (result == -1)
        cout << "Khong tim thay!\n";
    else
        cout << "Tim thay tai vi tri chi so: " << result << endl;

    return 0;
}
