#include <iostream>
using namespace std;

void nhapMang(int A[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap mang:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            Swap(A[i], A[j]);
        }
    }

    Swap(A[i + 1], A[high]);
    return i + 1;
}

void Quick_Sort(int A[], int low, int high) {
    if (low < high) {
        int pi = Partition(A, low, high);
        Quick_Sort(A, low, pi - 1);
        Quick_Sort(A, pi + 1, high);
    }
}

int main() {
    int n;
    int A[100];

    nhapMang(A, n);

    Quick_Sort(A, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
