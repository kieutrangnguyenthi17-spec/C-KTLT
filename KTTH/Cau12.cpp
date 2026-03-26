#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4};
    int *p = arr;        // p trỏ đến arr[0]
    int *q = arr + 3;    // q trỏ đến arr[3]
    cout << q - p;       // hiệu hai con trỏ
    return 0;
}
