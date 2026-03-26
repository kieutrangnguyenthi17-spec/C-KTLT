#include <iostream>
using namespace std;

void nhapMang(int A[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap mang:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void Merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
}

void Merge_Sort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        Merge_Sort(A, left, mid);
        Merge_Sort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

int main() {
    int n;
    int A[100];

    nhapMang(A, n);

    Merge_Sort(A, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
