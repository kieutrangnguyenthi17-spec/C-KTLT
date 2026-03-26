#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3};
    int *p = a;

    cout << *p++ << ", ";
    cout << *p;

    return 0;
}
